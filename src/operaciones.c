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

/// @fn float addNumbers(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los suma.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la suma.
float addNumbers (float firstNumber, float secondNumber)
{
    return firstNumber + secondNumber;
}

/// @fn float restaNumeros(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los resta.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la resta.
float restaNumeros(float firstNumber, float secondNumber)
{
    return firstNumber - secondNumber;
}

/// @fn float divideNumbers(float, float, char*)
/// @brief Funcion que recibe dos numeros flotantes y los divide.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @param errorMessage char* Mensaje de error en caso que la division no se pueda realizar (si el segundo numero es un cero).
/// @return float con resultado de la division.
float divideNumbers(float firstNumber, float secondNumber, char* errorMessage)
{
    float returnValue = 0;
    if(secondNumber == 0)
    {
        returnValue = -1;
    }
    else
    {
        returnValue = firstNumber / secondNumber;
    }
    return returnValue;
}

/// @fn float multiplyNumbers(float, float)
/// @brief Esta funcion recibe dos numeros flotantes y los multiplica.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la multiplicacion.
float multiplyNumbers(float firstNumber, float secondNumber)
{
    return firstNumber * secondNumber;
}

/// @fn int getFactorial(float)
/// @brief Funcion recibe un numero flotante y realiza el factoreo del mismo.
///
/// @param float Numero para factorizar.
/// @return int Resultado del factoreo.
double getFactorial(float number)
{
	double factorial;
    if(number >= 0)
    {
        factorial = 1;
        for(int i =2; i <= number; i++)
        {
        	factorial = factorial * i;
        }
    }
    return factorial;
}

