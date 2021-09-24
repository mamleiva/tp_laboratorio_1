/*
 * funciones.c
 *
 *  Created on: 22 sep. 2021
 *      Author: Leiva Miguel
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "operaciones.h"

void mostrarMenu(){ //comienzo de mostrar menu.
    int opcionIngresada; //opcion ingresada.
    int opcionContinuar = 's'; //variable que controla si continua el programa o no.
    float primeroNumero = 0; //primer operando ingresado
    float segundoNumero = 0; //segundo operando ingresado
    float resultadoResta; //variable que guarda el resultado de la resta
    float resultadoSuma; //variable que guarda el resultado de la suma
    float resultadoDivision; //variable que guarda el resultado de la division
    int retornoDivision; //variable que guarda el retorno de la division
    float multiplication; //variable que guarda el resultado de la multiplicacion
    double factorialPrimerNumero; //variable que guarda el resultado del factorial del primer numero
    double factorialSegundoNumero; //variable que guarda el resultado del factorial del segundo numero
    int flagPrimerOperando = 0; //bandera para primer operando.
    int flagSegundoOperando = 0; //bandera para segundo operando.
    int flagCalculos = 0; //bandera para saber si se realizaron los calculos.


    do{
        opcionIngresada = getInt("Seleccione una opcion: \n1.Ingresar primer operando.\n2.Ingresar segundo operando.\n3.Calcular todas las operaciones.\n4.Informe de resultados.\n5.Salir.\n");
        switch(opcionIngresada){//opciones de menu
        case 1:
            //ingreso del primer numero
            primeroNumero = getFloat("Ingrese un primer operando:");
            printf("Ingrese el primer operando es: %.2f\n\n", primeroNumero);
            flagPrimerOperando = 1;
            break;
        case 2:
            //ingreso del segundo numero
            segundoNumero = getFloat("Ingrese un segundo operando:");
            printf("Ingrese el segundo operando es: %.2f\n\n", segundoNumero);
            flagSegundoOperando = 1;
            break;
        case 3: //calculos a realizar
            //verificacion de los operandos
            if(flagPrimerOperando == 0)
            {
                printf("Usted no ha ingresado un primer operando. Seleccione 1 para ingresarlo.\n");
            }
            else
            {
                if(flagSegundoOperando == 0)
                {
                    printf("Usted no ha ingresado un segundo operando. Seleccione 2 para ingresarlo.\n");
                }
                else
                {//si se ingresaron los operandos, se informa al usuario de las operaciones a realizar.
                	system("@cls||clear");
                    printf("Se van a realizaran las siguientes operaciones:\n");
                    printf("Suma: %.2f + %.2f\n", primeroNumero, segundoNumero);
                    printf("Resta: %.2f - %.2f\n", primeroNumero, segundoNumero);
                    printf("Division: %.2f / %.2f\n", primeroNumero, segundoNumero);
                    printf("Multiplicacion: %.2f * %.2f\n", primeroNumero, segundoNumero);
                    printf("Factorizacion del primer operando: %.2f!\n", primeroNumero);
                    printf("Factorizacion del segundo operando: %.2f!\n", segundoNumero);
                    printf("\n\n");
                    resultadoSuma = sumaNumeros(primeroNumero,segundoNumero);
                    resultadoResta = restaNumeros(primeroNumero,segundoNumero);
                    retornoDivision = division(&resultadoDivision, primeroNumero, segundoNumero);
                    multiplication = multilicacionDosNumeros(primeroNumero,segundoNumero);
                    factorialPrimerNumero = factorial(primeroNumero);
                    factorialSegundoNumero = factorial(segundoNumero);
                    flagCalculos = 1;

                }
            }
            break;
        case 4:
            //Muestro el informe de los resultados de las operaciones (si se pudieron realizar)
        	if(flagCalculos==0)
        	{
        		printf("Usted no ha realizado los calculos, Seleccione la opcion 3 antes.\n");
        	}
        	else
        	{
        		system("@cls||clear");
				printf("El informe de los resultados es:\n");
				printf("El resultado de %.2f + %.2f es: %.2f\n", primeroNumero, segundoNumero, resultadoSuma);
				printf("El resultado de %.2f - %.2f es: %.2f\n", primeroNumero, segundoNumero, resultadoResta);

				//validacion de division
				if(retornoDivision==0)
				{
					printf("El resultado de %.2f / %.2f es: %.2f\n", primeroNumero, segundoNumero, resultadoDivision);
				}
				else
				{
					printf("La division por CERO no es posible. Si quiere realizar una division, ingrese un segundo operando mayor a cero\n");
				}//fin de validacion para que no se divida por cero.

				printf("El resultado de %.2f * %.2f es: %.2f\n", primeroNumero, segundoNumero, multiplication);
				printf("El factorial de (%.2f) es: %.lf y el factorial de (%.2f) es: %lf\n\n", primeroNumero, factorialPrimerNumero, segundoNumero, factorialSegundoNumero);

        	}
            break;
        case 5:
            //salida del programa
            printf("Saliste de la calculadora!!!.\n");
            printf("\n\n");
            opcionContinuar ='n';
            break;
        default:
            printf("Dato invalido. ingrese 1, 2, 3, 4, 5.\n");  //si ingresa un dato invalido vuelve al while
            break;
        }//switch
    }while(opcionContinuar == 's');// fin del dowhile
}//fin de mostrar_menu

float getFloat(char* message){
    float number;
    printf(message);
    fflush(stdin);
    scanf("%f", &number);
    return number;
}

int getInt(char* message){
    int number;
    printf(message);
    fflush(stdin);
    scanf("%d", &number);
    return number;
}


