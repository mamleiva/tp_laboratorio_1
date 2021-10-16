/*
 * inputs.c
 *
 *  Created on: 14 oct. 2021
 *      Author: martinl
 */

#include "inputs.h"

/**
 * @fn int getIntMinMax(char*, int, int)
 * @brief obtiene un numero entre un rango minimo y maximo
 *
 * @param mensaje para mostrar, ingresarlo SIN ":" NI espacio, se agrega automaticamente con los min y max
 * @param min numero minimo a permitir
 * @param max numero maximo a permitir
 * @return devuelve el numero dentro de los valores
 */
int getIntMinMax(char *mensaje, int min, int max)
{
    int numero;
    while((getValidIntMinMax(&numero, mensaje, min, max)) == -1){
        printf("Error. Ingrese solo numeros entre el rango: [%d] y [%d] \n", min, max);
    }
    return numero;
}

/**
 * @fn int getValidIntMinMax(int*, char*, int, int)
 * @brief valida que el numero este en el rango y lo devuelve por puntero
 *
 * @param numero dir de mem del numero a analizar
 * @param mensaje a mostrar recibido por param
 * @param min numero minimo a analizar
 * @param max numero maximo a analizar
 * @return Devuelve -1 si no es un entero o es un entero mas otro valor no entero, o esta fuera de rango o 0 si es todo entero
 */
int getValidIntMinMax(int* numero, char* mensaje, int min, int max)
{
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada [20];
    int i;
    printf("%s entre [%d] y [%d]: ", mensaje, min, max);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada);
    for(i=0; i<strlen(cadenaCargada) ; i++){
        if(cadenaCargada[i]!='\0'){
            if(cadenaCargada[i] < '0' || cadenaCargada[i] > '9'){
                sePudo = -1;
            }
            if(cadenaCargada[i]!=' '){
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 1){
        sePudo = -1;
    }
    if(sePudo == 1 ){
        *numero = atoi (cadenaCargada);
    }
    while(!(*numero >= min && *numero <= max)) //valido que este dentro del rango min y max.
        {
        	sePudo = -1;
        	break;
        }
    return sePudo;
}

/** \brief Pide un entero y lo devuelve
 *
 * \param mensaje char* mensaje de ingreso
 * \return int Entero  validado
 *
 */
int getInt(char *mensaje)
{
    int numero;
    while((getValidInt(&numero, mensaje)) == -1){
        printf("Error. Ingrese solo numeros!\n");
    }
    return numero;
}

/** \brief Valida si el valor ingresado es un entero o no es llamada por getInt
 *
 * \param numero int* valor ingresado
 * \param mensaje char* mensaje recibido por param
 * \return int Devuelve "-1" si no es un int o es un entero con espacio, o "0" si es solo int.
 *
 */
int getValidInt(int* numero, char* mensaje){
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada [20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada);
    for(i=0; i<strlen(cadenaCargada) ; i++){
        if(cadenaCargada[i]!='\0'){
            if(cadenaCargada[i] < '0' || cadenaCargada[i] > '9'){
                sePudo = -1;
            }
            if(cadenaCargada[i]!=' '){
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 1){
        sePudo = -1;
    }
    if(sePudo == 1){
        *numero = atoi (cadenaCargada);
    }
    return sePudo;
}

/** \brief Pide un caracter lo pasa a minuscula y lo devuelve
 *
 * \param mensaje[] char Mensaje a mostrar
 * \return char Caracter ingresado
 *
 */
char getChar(char mensaje[]){
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    tolower(letter);
    return letter;
}

/** \brief Valida que sea un caracter
 *
 * \param letra char* Valor ingresado
 * \return int Devuelve "1" si no es una letra, o "0" si es letra
 *
 */
int getValidChar(char* letra){
    int retorno = 0;
    if(*letra <'a' || *letra>'z'){
        printf("Error. ingrese UNA sola letra.\n");
        retorno = 1;
    }
    return retorno;
}

/** \brief Esta funcion pide el ingreso de 's' o de 'n'  y lo pasa a minuscula
 *
 * \param mensaje[] char Mensaje de ingreso
 * \return char Devuelve el caracter validado "s" o "n"
 *
 */
char getConfirmacion(char mensaje[]){
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    while(letter!='s' && letter!='n'){
        printf("Error. Ingrese s para SI o n para NO:\n");
        fflush(stdin);
        scanf("%c", &letter);
    }
    tolower(letter);
    return letter;
}

/** \brief Pide un string y lo guarda en el vector cadena
 *
 * \param mensaje[] char Mensaje a Mostrar
 * \param cadena[] char Vector donde se guarda el string ingresado
 * \return void
 *
 */
void getString(char mensaje[], char cadena[]){
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    firstToUpper(cadena);
}

/** \brief Verifica que el string ingresado sea solo de letras.
 *
 * \param cadena[] char vector a validar
 * \return int Devuelve "-1" (si hay otros caracteres que no sean letras, o "0" si son solo letras):
 *
 */
int getStringLetras(char cadena[]){
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);
    for(i=0;i<tam;i++){
        if(cadena[i] != '\0'){
            if ((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z') && cadena[i]!=' '){
                flag = -1;
            }
            if(cadena[i]!=' '){
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 0){
        flag = -1;
    }
    return flag;
}

/** \brief Pide un string y lo valida llamando la funcion "getStringLetras"
 * y pasa primer letra a mayuscula con la funcion "firstToUpper"
 * \param mensaje[] char Mensaje a mostrar
 * \param cadena[] char vector destino para el string validado
 * \return void
 *
 */
void pedirCadena (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    while(getStringLetras(cadena)== -1){
        printf("Error. Ingrese solo letras!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
    firstToUpper(cadena);
}

/** \brief Convierte el string a minuscula y despues la primera letra del string a mayuscula.
 *
 * \param cadena[] char vector con la cadena ingresada
 * \return void
 *
 */
void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]); //primer letra a mayuscula
    for(i=0;i<tam;i++){
        if(cadena[i]!='\0'){
            if(isspace(cadena[i])){
                cadena[i+1] = toupper(cadena[i+1]); //convierte lo siguiente a " " a mayuscula
            }
        }
    }
}

/** \brief Recibe un numero float y lo valida
 *
 * \param numero float* Numero a validar
 * \param mensaje char* Mensaje a mostrar
 * \return int Devuelve "-1" si no es float o "0" si es float
 *
 */
int getValidFloat(float* numero, char* mensaje)
{
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada [20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada);
    for(i=0; i<strlen(cadenaCargada) ; i++){
        if(cadenaCargada[i]!='\0'){
            if((cadenaCargada[i] < '0' || cadenaCargada[i] > '9') && cadenaCargada[i]!='.'){
                sePudo = -1;
            }
            if(cadenaCargada[i]!=' '){
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 1){
        sePudo = -1;
    }
    if(sePudo == 1){
        *numero = atof (cadenaCargada);
    }
    return sePudo;
}

/** \brief Pide un float y lo valida con la funcion getValidFloat.
 *
 * \param mensaje[] char Mensaje a mostrar
 * \return float Devuelve el numero float validado.
 *
 */
float getFloat(char mensaje[]){
    float numero;
    while((getValidFloat(&numero, mensaje)) == -1){
        printf("Error. Ingrese solo numeros!\n");
    }
    return numero;
}


