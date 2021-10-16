/*
 * ArrayEmployees.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Miguel Leiva
 */

#define TRUE 0
#define FALSE 1
#define SECTORMIN 1
#define SECTORMAX 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

//declaracion de funciones para Employees, el doxygen esta en "ArrayEmployees.c" porque asi recomendaba el documento desarrollo de una biblioteca

void showMenu(Employee* list, int len);

int initEmployees(Employee* list, int len);

void showData(char name[],char lastName[],float salary,int sector);

int initIds(Employee* list, int len);

int printEmployees(Employee* list, int length);

void showOneEmployee(Employee sEmployee);

int getIsEmpty(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int getNewId(Employee* list, int len);

int loadEmployee(Employee* list, int len);

void getDataEmployee(char name[],char lastName[],float* salary,int* sector);

int findEmployeeById(Employee* list, int len,int id);

int deleteEmployee(Employee* list, int len);

int removeEmployee(Employee* list, int len, int id);

int getIsOccupied(Employee* list, int len);

int modificarEmpleado(Employee* list, int len);

int informarEmpleado(Employee* list, int len);

void menuInformesSalarios(Employee* list, int len);

int sortEmployees(Employee* list, int len, int order);

float getTotalSalarios(Employee* list, int len);

float getPromedioSalarios(Employee* list, int len);

int getMaximoSalario(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
