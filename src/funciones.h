/*
 * funciones.h
 *
 *  Created on: 22 sep. 2021
 *      Author: Leiva Miguel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @fn void mostrarMenu(void)
/// @brief Funcion que muestra por consola un menu; para realizar el ingreso de operandos y operaciones matematicas
/// sobre los numeros ingresados.
///
void mostrarMenu(void);

/// @fn int getInt(char*)
/// @brief Funcion que pide y devuelve un entero.
///
/// @param message char* Mensaje para solicitar el ingreso de un numero int.
/// @return int Devuelve el numero ingresado.
int getInt(char* message);

/// @fn float getFloat(char*)
/// @brief Funcion que pide y devuelve un flotante, valida que se un numero ingresado.
///
/// @param message char* Mensaje para solicitar el ingreso de un numero float.
/// @return float Devuelve el numero ingresado.
float getFloat(char* message);

#endif /* FUNCIONES_H_ */
