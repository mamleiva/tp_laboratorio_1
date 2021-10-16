/*
 * inputs.h
 *
 *  Created on: 14 oct. 2021
 *      Author: martinl
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef INPUTS_H_
#define INPUTS_H_

//declaracion de funciones para Employees, el doxygen esta en "inputs.c" porque asi recomendaba el documento desarrollo de una biblioteca


int getIntMinMax(char *mensaje, int min, int max);

int getValidIntMinMax(int* numero, char* mensaje, int min, int max);

int getInt(char *mensaje);

int getValidInt(int* numero, char *mensaje);

char getChar(char mensaje[]);

int getValidChar(char* letra);

char getConfirmacion(char mensaje[]);

void getString(char mensaje[], char cadena[]);

int getStringLetras(char cadena[]);

void pedirCadena (char mensaje[], char cadena[]);

void firstToUpper(char cadena[]);

int getValidFloat(float* numero, char* mensaje);

float getFloat(char mensaje[]);




#endif /* INPUTS_H_ */
