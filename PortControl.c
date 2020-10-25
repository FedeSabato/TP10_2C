/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PortControl.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MASK16 0x0001
#define MASK8 0x01

typedef union
{
    uint16_t D;     //Declaro al puerto D como union de dos puertos de 8 bits
    struct
    {
        //El orden de declaracion esta dado por el Endian (Little Endian).
        
        uint8_t B;  //Declaro puerto B de 8 bits.
        uint8_t A;  //Declaro puerto A de 8 bits.
    };
    
    
}puerto_t;

static puerto_t port; 

void bitSet(char p , int b){

    if(((p== 'd')||(p=='D')) && (b>=0) && (b<=15)){
    
        uint16_t mask = MASK16; //Definimos mask como la mask16 
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        port.D |= mask; //Hacemos OR para modificar solo ese bit en VALOR = 1
        
    }
    else if(((p== 'b')||(p=='B')) && (b>=0) && (b<=7)){
    
        uint16_t mask = MASK8; //Definimos mask como la mask8
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        port.B |= mask; //Hacemos OR para modificar solo ese bit en VALOR = 1
        
    }
    else if(((p== 'a')||(p=='A')) && (b>=0) && (b<=7)){
    
        uint16_t mask = MASK8; //Definimos mask como la mask8
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        port.A |= mask; //Hacemos OR para modificar solo ese bit en VALOR = 1
        
    }

}


void bitClr(char p , int b){

    if(((p== 'd')||(p=='D')) && (b>=0) && (b<=15)){
    
        uint16_t mask = MASK16; //Definimos mask como la mask16 
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        mask = ~mask; //Negamos mask para poder hacer AND y no modificar todos los bits
        port.D &= mask; //Hacemos AND para modificar solo ese bit en VALOR = 0
        
    }
    else if(((p== 'b')||(p=='B')) && (b>=0) && (b<=7)){
    
        uint8_t mask = MASK8; //Definimos mask como la mask8
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        mask = ~mask; //Negamos mask para poder hacer AND y no modificar todos los bits
        port.B |= mask; //Hacemos AND para modificar solo ese bit en VALOR = 0
        
    }
    else if(((p== 'a')||(p=='A')) && (b>=0) && (b<=7)){
    
        uint8_t mask = MASK8; //Definimos mask como la mask8
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        mask = ~mask; //Negamos mask para poder hacer AND y no modificar todos los bits
        port.A |= mask; //Hacemos AND para modificar solo ese bit en VALOR = 0
        
    }

}


int bitGet(char p , int b){
    
    int state;

    if(((p== 'd')||(p=='D')) && (b>=0) && (b<=15)){
    
        uint16_t mask = MASK16;
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        if((port.D) & mask){ ////Usamos AND para ver si coincide el 1 asignado en mask con el bit solicitadp
        
            state = 1;
            
        }
        else{
        
            state = 0;
        
        }
             
    }
    else if(((p== 'b')||(p=='B')) && (b>=0) && (b<=7)){
    
       uint8_t mask = MASK8;
       mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
       if((port.B) & mask){ ////Usamos AND para ver si coincide el 1 asignado en mask con el bit solicitadp
        
           state = 1;
            
       }
       else{
       
           state = 0;
        
       }
    }
    else if(((p== 'a')||(p=='A')) && (b>=0) && (b<=7)){
    
       uint8_t mask = MASK8;
       mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
       if((port.A) & mask){     //Usamos AND para ver si coincide el 1 asignado en mask con el bit solicitadp
        
           state = 1;
            
       }
       else{
       
           state = 0;
        
       }
    }
    
}


void bitToggle (char p , int b){
    
    if(((p== 'd')||(p=='D')) && (b>=0) && (b<=15)){
    
        uint16_t mask = MASK16; //Definimos mask como la mask8
        mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
        port.D ^= mask; 
                         
    }
    else if(((p== 'b')||(p=='B')) && (b>=0) && (b<=7)){
    
       uint8_t mask = MASK8; //Definimos mask como la mask8
       mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
       port.B ^= mask;
        
    }
    else if(((p== 'a')||(p=='A')) && (b>=0) && (b<=7)){
    
       uint8_t mask = MASK8; //Definimos mask como la mask8
       mask <<= b; //Pusheamos a izq. cuantas veces se haya pedido
       port.A ^= mask; 
       
    }   
    
}


void maskOn(char p , int b){ //Misma logica que bitSet, b en este caso seria la mascara casteada a uint
    
    if((p== 'd')||(p=='D')){
    
        port.D |= (uint16_t)b;
        
    }
    else if((p== 'b')||(p=='B')){
    
        port.B |= (uint8_t)b;
        
    }
    else if((p== 'a')||(p=='A')){
    
        port.A |= (uint8_t)b;
       
    }
    
}


void maskOff(char p , int b){ //Misma logica que bitClr, b en este caso seria la mascara casteada a uint
    
    if((p== 'd')||(p=='D')){
    
        port.D &= (uint16_t)~b;
        
    }
    else if((p== 'b')||(p=='B')){
    
        port.B &= (uint8_t)~b;
        
    }
    else if((p== 'a')||(p=='A')){
    
        port.A &= (uint8_t)~b;
       
    }
    
}


void maskToggle(char p , int b){ //Misma logica que bitToggle, b en este caso seria la mascara casteada a uint
    
    if((p== 'd')||(p=='D')){
    
        port.D ^= (uint16_t)b;
        
    }
    else if((p== 'b')||(p=='B')){
    
        port.B ^= (uint8_t)b;
        
    }
    else if((p== 'a')||(p=='A')){
    
        port.A ^= (uint8_t)b;
       
    }
    
}