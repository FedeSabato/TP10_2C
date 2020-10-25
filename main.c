/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: fede
 *
 * Created on October 25, 2020, 1:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "PortControl.h"

#define ERROR -3
#define QUIT  -2

int input(void);
void printPort(void);

int main(void) {
    
    int mask= 0xFF;
    int in;
    
    printPort();

    while(in!=QUIT){
        
        in = input();
        
        if((in>=0)&&(in<=7)){
        
            bitToggle('A',in);
            
        }
        else if ((in=='s')||(in=='S')){
        
            maskOn('A',mask);
            
        }
        else if ((in=='c')||(in=='C')){
        
            maskOff('A',mask);
            
        }
        else if((in=='t')||(in=='T')){
        
            maskToggle('A',mask);
        
        }     
        
        printPort();
    
    }   
    
}

int input(void){
    
    char c;
    int ret, cont=0;

    while((c=getchar())!= '\n'){
    
        if((c>='0')&&(c<='7')){
        
            ret = c-'0';
            cont++;
        
        }
        else if((c=='t')||(c=='T')||(c=='c')||(c=='C')||(c=='s')||(c=='S')){
        
            ret = c;
            cont++;
        
        }
        else if((c=='q')||(c=='Q')){
        
            ret = QUIT;
            cont++;
            
        }
        
        if(cont>=2){
        
            ret = ERROR;
            printf("Error en datos ingresados");
            
        }
        
    }
    
    return ret;

}

void printPort (void)
{
    int i=0;
       
    printf("|");
    
    for(i=0; i<=7;i++)
    {
        
        if(bitGet('a',i))    //Si bitGet devuelve 1, porque el bit esta prendido
        {
            printf("*");        // imprimo un *
        }
        else                    //Caso contrario (si devuelve un 0) 
        {
            printf(" ");        // imprimo un espacio
        }
        
        printf("|");
    }
    
    printf("\n");
}
