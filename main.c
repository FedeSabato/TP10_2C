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

int main(int argc, char** argv) {

    while(input()!=QUIT){
        
        
    
    }
    
    
}

int input(void){
    
    char c;
    int ret, cont=0;

    while((c=getchar())!= '\n'){
    
        if((c>=0)&&(c<=7)){
        
            ret = c - '0';
            cont++;
        
        }
        if((c=='t')||(c=='T')||(c=='c')||(c=='C')||(c=='s')||(c=='S')){
        
            ret = c;
            cont++;
        
        }
        if((c=='q')||(c=='Q')){
        
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

void printPort(void){

    int i;
    
    printf('|');
    
    for(i=0;i<8;i++){
        
        if(bitGet('A',i)==1){
        
            printf('+');
            
        }
        else if(bitGet('A',i)==0){
        
            printf(' ');
            
        }
        
        printf('|');
        
    
    }
    printf('\n');
}
