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

#include "PortControl.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR -3
#define PRIN -2
#define FIN -1

int input(void);
void printPort(void);

int main(void) {
    
    int mask= 0xFF;
    int in;
    printf("Ingrese un numero entre 0 y 7 para prender el LED correspondiente.\nIngrese s para prender todos, c para apagar todos, t para invertirlos y q para salir:\n");
    do
    {
        printf("Puerto A: ");
        printPort();    //Imprime las LEDs del puerto A.
        printf("\n");
        do
        {
            printf("\nIngrese un valor: ");
            in = input(); //Se ingresa un valor.
            if (in == ERROR)   //Avisa que lo ingresado es invalido.
            {
                printf("Se ingreso un numero invalido.\n");
            }
        }
        while (in == ERROR);   //Si lo ingresado es invalido vuelve a pedir el valor.
        
        if ( (in >= 0) && (in <= 7) ) //Si se ingreso un numero, pone ese LED en 1.
        {
            bitSet ('A', in);
        }
        else if (in == 't')  //Si se ingreso t, se invierten los LEDs.
        {
            maskToggle('A', mask);
        }
        else if (in == 'c')  //Si se ingreso c, se apagan todos los LEDs.
        {
            maskOff('A', mask);
        }
        else if (in == 's')  //Si se ingreso s, se encienden todos los LEDs.
        {
            maskOn('A', mask);
        }
    }
    while (in != 'q');   //Si se ingreso q, sale del programa.
}

int input (void)
{
    char c = getchar();
    int estado = PRIN, rta = ERROR;    //estado permite ingresar al primer if solo una vez.
    while (c != '\n')
    {
            if ( ( ((c >= '0') && (c <= '7')) || (c == 't') || (c == 'c') || (c == 's') || (c == 'q') ) && (estado != FIN) )    //Si se ingreso algo valido.
            {
                if ( (c >= '0') && (c <= '7') )
                {
                    c -= '0';   //Se transforma el numero de ASCII a decimal.
                }
                rta = c;
                estado = FIN;   //Cambia el estado.
            }
            else
            {
                rta = ERROR;  //Si se ingreso algo invalido o no se ingreso nada devuelve error.
                estado = FIN;
            }
            c = getchar();
    }
    return rta;
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
