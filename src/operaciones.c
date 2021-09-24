/*
 * operaciones.c
 *
 *  Created on: 22 sep. 2021
 *      Author: Leiva Miguel
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "funciones.h"

/// @fn float sumaNumeros(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los suma.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la suma.
float sumaNumeros (float primerNumero, float segundoNumbero)
{
    return primerNumero + segundoNumbero;
}

/// @fn float restaNumeros(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los resta.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la resta.
float restaNumeros(float primerNumero, float segundoNumero)
{
    return primerNumero - segundoNumero;
}


/**
 * @fn int division(float*, float, float)
 * @brief Funcion que recibe puntero a floar, dos numeros flotantes y los divide.
 * @param pResultado puntero a resultado &varconresultado
 * @param primerNumero float Primer numero flotante.
 * @param segundoNumero float Segundo numero flotante
 * @return return int, -1 si hubo error, 0 si no hubo error.
 */
int division(float* pResultado, float primerNumero, float segundoNumero)
{
    int retorno = -1;
    if(pResultado != NULL && segundoNumero != 0)
    {
    	*pResultado = primerNumero / segundoNumero;
        retorno = 0;
    }

    return retorno;
}

/// @fn float multilicacionDosNumeros(float, float)
/// @brief Esta funcion recibe dos numeros flotantes y los multiplica.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la multiplicacion.
float multilicacionDosNumeros(float primerNumero, float segundoNumero)
{
    return primerNumero * segundoNumero;
}

/// @fn int factorial(float)
/// @brief Funcion recibe un numero flotante y realiza el factoreo del mismo.
///
/// @param float Numero para factorizar.
/// @return int Resultado del factoreo.
double factorial(float number)
{
	double fact;
    if(number >= 0)
    {
        fact = 1;
        for(int i =2; i <= number; i++)
        {
        	fact = fact * i;
        }
    }
    return fact;
}

