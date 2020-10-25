/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PortControl.h
 * Author: fede
 *
 * Created on October 25, 2020, 1:06 PM
 */

#ifndef PORTCONTROL_H
#define PORTCONTROL_H

//bitSet: Dado un puerto y un número de bit, debe cambiar su estado a 1.
void bitSet(char p , int b);

//bitClr: Dado un puerto y un número de bit, debe cambiar su estado a 0.
void bitClr(char p , int b);

//bitGet: Dado un puerto y un número de bit, debe devolver su valor.
int bitGet(char p , int b);

//bitToggle:  Dado  un  puerto  y  un  número  de  bit,  debe  cambiar  al  
//estado opuesto en el que está
void bitToggle (char p , int b);

//maskOn: Dado un puerto y una máscara, debe prender todos aquellos bits 
//que estén  prendidos  en  la  máscara,  sin  cambiar  el  estado  de  los 
//restantes.
void maskOn(char p , int b);

//maskOff: Dado un puerto y una máscara, debe apagar todos aquellos bits que
//estén  prendidos  en  la  máscara,  sin  cambiar  el  estado  de  los  
//restantes.
void maskOff(char p , int b);

//maskToggle: Dado un puerto y una máscara, debe cambiar el estado de todos 
//aquellos  bits  que  estén  prendidos  en  la  máscara  al  opuesto,  
//sin  cambiar  el estado de los restantes
void maskToggle(char p , int b);

#endif /* PORTCONTROL_H */

