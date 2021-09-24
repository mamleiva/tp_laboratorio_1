/*
 * operaciones.h
 *
 *  Created on: 22 sep. 2021
 *      Author: Leiva Miguel
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/// @fn float sumaNumeros(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los suma.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la suma.
float sumaNumeros (float, float);

/// @fn float restaNumeros(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los resta.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la resta.
float restaNumeros(float, float);

 /// @fn int division(float*, float, float)
 /// @brief Funcion que recibe puntero a floar, dos numeros flotantes y los divide.
 /// @param pResultado puntero a resultado &varconresultado
 /// @param firstNumber float Primer numero flotante.
 /// @param secondNumber float Segundo numero flotante
 /// @return return int, -1 si hubo error, 0 si no hubo error.
int division(float* pResultado, float firstNumber, float secondNumber);

/// @fn float multilicacionDosNumeros(float, float)
/// @brief Esta funcion recibe dos numeros flotantes y los multiplica.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la multiplicacion.
float  multilicacionDosNumeros (float, float);

/// @fn int factorial(float)
/// @brief Funcion recibe un numero flotante y realiza el factoreo del mismo.
///
/// @param float Numero para factorizar.
/// @return int Resultado del factoreo.
double  factorial (float);

#endif /* OPERACIONES_H_ */
