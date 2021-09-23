/*
 * operaciones.h
 *
 *  Created on: 22 sep. 2021
 *      Author: Leiva Miguel
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/// @fn float addNumbers(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los suma.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la suma.
float addNumbers (float, float);

/// @fn float restaNumeros(float, float)
/// @brief Funcion que recibe dos numeros flotantes y los resta.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la resta.
float restaNumeros(float, float);

/// @fn float divideNumbers(float, float, char*)
/// @brief Funcion que recibe dos numeros flotantes y los divide.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @param errorMessage char* Mensaje de error en caso que la division no se pueda realizar (si el segundo numero es un cero).
/// @return float con resultado de la division.
float  divideNumbers(float, float, char* errorMessage);

/// @fn float multiplyNumbers(float, float)
/// @brief Esta funcion recibe dos numeros flotantes y los multiplica.
///
/// @param float Primer numero flotante.
/// @param float Segundo numero flotante.
/// @return float Resultado de la multiplicacion.
float  multiplyNumbers (float, float);

/// @fn int getFactorial(float)
/// @brief Funcion recibe un numero flotante y realiza el factoreo del mismo.
///
/// @param float Numero para factorizar.
/// @return int Resultado del factoreo.
double  getFactorial (float);

#endif /* OPERACIONES_H_ */
