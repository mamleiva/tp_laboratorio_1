/*
 * ArrayEmployees.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Miguel Leiva
 */

#include "ArrayEmployees.h"

/** \brief muestra un menu de opciones para de altas, bajas y modificaciones de empleados
 *
 * \param list Employee* puntero a un array de empleados
 * \param len int largo del array de empleados
 * \return void
 *
 */
void showMenu(Employee list[], int len) {
	int option;
	int retorno;
	char option_continue = 'n';
	int seCargoUnEmpleado = 0;
	initEmployees(list, len);
	initIds(list, len);

	do {
		system("cls");
		printf("******* MENU DE GESTION DE EMPLEADOS ******* \n");
		printf("*******      EMPRESA MYDE S.A.       ******* \n");

		option =
				getInt(
						"Opciones:\n1. ALTAS.\n2. MODIFICAR.\n3. BAJA.\n4. INFORMES.\n5. SALIR.\n");
		switch (option) {
		case 1:	///ALTAS
			retorno = loadEmployee(list, len);
			switch (retorno) {
			case -1:
				printf(
						"No hay lugar disponible, para guardar un empleado nuevo.\n");
				break;
			case 0:
				printf("Los datos se cargaron correctamente.\n");
				seCargoUnEmpleado = 1;
				break;
			case 1:
				printf("Error, no se pudo acceder a la opcion elegida.\n");
				break;
			case 2:
				printf("El usuario cancelo la carga.\n");
				break;
			}
			printf("\n");
			system("pause");
			break;
		case 2:	///MODIFICACIONES
			if (seCargoUnEmpleado == 1) {
				retorno = modificarEmpleado(list, len);
				switch (retorno) {
				case -1:
					printf("No se encontro el dato.\n");
					break;
				case 0:
					printf("El usuario cancelo la accion.\n");
					break;
				case 1:
					printf("Se modificaron correctamente los datos.\n");
					break;
				}
			} else {
				printf("Error! Debe dar de alta un empleado antes.\n");
			}
			printf("\n");
			system("pause");
			break;
		case 3:	///BAJAS
			if (seCargoUnEmpleado == 1) {
				retorno = deleteEmployee(list, len);
				switch (retorno) {
				case -1:
					printf("Error. No se pudo completar la accion. \n");
					break;
				case 0:
					printf("Se ha eliminado al empleado de la lista.\n");
					break;
				case 1:
					printf("El empleado no existe.\n");
					break;
				case 2:
					printf("El usuario cancelo la accion.\n");
					break;
				}
			} else {
				printf("Error! Debe dar de alta un empleado antes.\n");
			}
			printf("\n");
			system("pause");
			break;
		case 4:	///INFORMES
			if (seCargoUnEmpleado == 1) {
				retorno = informarEmpleado(list, len);
				switch (retorno) {
				case -1:
					printf("Error! no se puede acceder a  los informes.\n");
					break;
				case 1:
					printf("Error! No se pudo realizar el ordenamiento.\n");
					break;
				}
			} else {
				printf("Error! Debe dar de alta un empleado antes.\n");
			}
			printf("\n");
			system("pause");
			break;
		case 5:
			option_continue =
					getChar(
							"Esta seguro que desea salir? Ingrese \"n\" para cancelar: ");
			printf("\n");
			system("pause");
			break;
		default:
			printf("Ha ingresado una opcion incorrecta.\n");
			printf("\n");
			system("pause");
			break;
		} //FIN del SWITCH
	} while (option_continue == 'n');
	printf("\n");
} //#####################FIN DEL MENU#################################

/** \brief Funcion pone la bandera (isEmpty) de todos los lugares del array de empleados en TRUE (0), para indicar que estan vacios
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array
 * \return int Devuelve 0 si realizo la inicializacion o -1 (si el largo del array es invalido o el puntero al array es NULL).
 *
 */
int initEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief muestra los de datos de empleado.
 *
 * \param name[] char nombre del empleado
 * \param lastName[] char apellido del empleado
 * \param salary float salario del empleado
 * \param sector int sector del empleado
 * \return void
 *
 */
void showData(char name[], char lastName[], float salary, int sector) {
	printf("\n");
	printf("Nombre: %s\n", name);
	printf("Apellido %s\n", lastName);
	printf("Salario: %.3f\n", salary);
	printf("Sector: %d\n", sector);
}

/** \brief inicializa los ids de todos los lugares del array de empleados en "0"
 *
 * \param list Employee* puntero a array de empleados
 * \param len int largo del array
 * \return int Devuelve "0" si realizo la inicializacion o "-1" (si el largo del array esta mal o el puntero de *list es NULL).
 *
 */
int initIds(Employee *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].id = 0;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Esta funcion imprime por cosola el array de empleados
 *
 * \param lista Employee* Recibe el puntero al array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve "0"si termino OK, o "-1" (si el largo del array es invalido o el puntero al array es NULL).
 *
 */
int printEmployees(Employee *list, int length) {
	int retorno = -1;
	int i;
	if (list != NULL && length > 0) {
		printf(
				"----------------------------------------------------------------------------------\n");
		printf("ID:\tNOMBRE:\t\tAPELLIDO:\t\tSALARIO:\t\tSECTOR:\n");
		printf(
				"----------------------------------------------------------------------------------\n");
		for (i = 0; i < length; i++) {
			if (list[i].isEmpty != TRUE) {
				retorno = 1;
				showOneEmployee(list[i]);
			}
		}
	}
	return retorno;
}

/** \brief Muestra a por consola un empleado de la lista
 *
 * \param sEmployee Recibe el empleado a mostrar
 * \return void
 *
 */
void showOneEmployee(Employee sEmployee) {
	printf(
			"----------------------------------------------------------------------------------\n");
	printf("%03d", sEmployee.id);
	printf("%12s", sEmployee.name);
	printf("%18s", sEmployee.lastName);
	printf("%22.2f", sEmployee.salary);
	printf("%23d\n", sEmployee.sector);
	printf(
			"----------------------------------------------------------------------------------\n");
}

/** \brief Busca el primer lugar libre en el array de empleados
 *
 * \param list Employee* puntero a array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve el indice del primer lugar libre dentro del array de empleados o -1 (si no hay lugar disponible, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
///int getIsEmpty(Employee *list, int len) {
int buscarLibre(Employee *list, int len) {
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief funcion que agrega en la primera posicion libre de la lista de empleados existente, los valores recibidos por parametros
 *
 * \param list Employee* puntero a array de empleados
 * \param len int largo del array de empleados
 * \param id int id del empleado nuevo
 * \param name[] char nombre del empleado nuevo
 * \param lastName[] char apellido del empleado nuevo
 * \param salary float salario del empleado nuevo
 * \param sector int sector del empleado nuevo
 * \return int Devuelve "0" si logro cargar o "-1" (si no hay lugar disponible, si el largo del array esta mal o si el array es NULL)
 *
 */

int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int retorno = -1;
	int lugar_Disponible = buscarLibre(list, len);

	if (lugar_Disponible != -1) {
		list[lugar_Disponible].id = id;
		strcpy(list[lugar_Disponible].name, name);
		strcpy(list[lugar_Disponible].lastName, lastName);
		list[lugar_Disponible].salary = salary;
		list[lugar_Disponible].sector = sector;
		list[lugar_Disponible].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int obtenerNuevoId(Employee*, int)
 * @brief asigna nuevos ids
 *
 * @param list lista Employee* puntero al array de empleados
 * @param len int largo del array de empleados
 * @return devuelve el id
 */
int obtenerNuevoId(Employee *list, int len) {
	int retorno = -1;
	int flag = 0;
	int nuevoId;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (flag == 0 || list[i].id > nuevoId) {
				nuevoId = list[i].id;
				flag = 1;
			}
		}
		retorno = nuevoId;
	}
	return retorno;
}

/** \brief carga datos del empleado en un lugar disponible dentro del array
 *
 * \param list Employee* puntero a array de empleados
 * \param len int  largo del array
 * \return int Devuelve "1" (si el largo del array esta mal o el puntero al array es NULL), -1 (si no hay lugar disponible), 0 (logro cargar al empleado dentro del array) o 2 (el usuario cancelo la carga)
 *
 */
int loadEmployee(Employee *list, int len) {
	int retorno = 1;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int id;
	char confirmacion;
	char opcion_continuar;
	int lugar_Disponible = buscarLibre(list, len);
	if (list != NULL && len > 0 && lugar_Disponible != -1) {
		do {
			getDataEmployee(name, lastName, &salary, &sector);
			printf("\n");
			printf("Estos son los datos ingresados:\n");
			showData(name, lastName, salary, sector);
			printf("\n");
			confirmacion =
					getConfirmacion(
							"Desea cargar los datos? Ingrese \"s\" para SI o \"n\" para NO: \n");
			if (confirmacion == 's') {
				id = obtenerNuevoId(list, len);
				id++; // sumo 1 asi el id arranca en 1.
				retorno = addEmployee(list, len, id, name, lastName, salary,
						sector); ///comente para corregir lo de check de lugar vacio
				opcion_continuar = 'n';
			} else if (confirmacion == 'n') {
				retorno = 2;
			}

			printf("\n");
		} while (opcion_continuar != 'n');
	} else {
		retorno = -1;
	}

	return retorno;
}

/** \brief Ppide los datos de empleado y los guarda en las vars recibidas como parametro
 *
 * \param name[] char nombre del empleado
 * \param lastName[] char apellido del empleado
 * \param salary float*  puntero float con salario del empleado
 * \param sector int* puntero a int que es el sector del empleado
 * \return void
 *
 */
void getDataEmployee(char name[], char lastName[], float *salary, int *sector) {
	printf("Ingrese los datos del empleado: \n");
	pedirCadena("Nombre del empleado: ", name);
	pedirCadena("Apellido del empleado: ", lastName);
	*salary = getFloat("Salario del empleado: ");
	*sector = getIntMinMax("Sector del empleado", SECTORMIN, SECTORMAX);
}

/** \brief Busca a un empleado por id y devuelve la posicion del empleado dentro del array de empleados
 *
 * \param list Employee* puntero a un array de empleados
 * \param len int largo del array de empleados
 * \param id int id del empleado a buscar
 * \return int Devuelve el indice del empleado o "-1" (si no encontro al empleado, si el largo del array esta mal o si el array es NULL)
 *
 */
int findEmployeeById(Employee *list, int len, int id) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				if (list[i].id == id) {
					retorno = i;
					break;
				}

			}
		}
	}
	return retorno;
}

/** \brief imprime en consola la lista de empleados existentes y da la opcion de eliminacion de un empleado.
 *
 * \param list Employee* puntero a un array de empleados
 * \param len int largo del array de empleados
 * \return int Devuelve "-1" (si el largo del array es invalido, si el array es NULL), "1" si no encontro al empleado por ID, "0" si pudo eliminar al empleado, "2" si el usuario cancela la operacion.
 */
int deleteEmployee(Employee *list, int len) {
	int retorno = -1;
	int id = 0;
	int index = 0;
	char confirmacion;
	if (list != NULL && len > 0) {
		printf("Estos son los empleados:\n");
		printEmployees(list, len);
		confirmacion =
				getConfirmacion(
						"Esta seguro de continuar? presione \"s\" para SI o \"n\" para CANCELAR\n");
		if (confirmacion != 'n') {
			id = getInt("\nIngrese el id del empleado que desea dar de baja:");
			printf("\n");
			index = findEmployeeById(list, len, id);
			if (index == -1) {
				retorno = 1;
			} else {
				showOneEmployee(list[index]);
				confirmacion =
						getChar(
								"\nEsta seguro que quiere eliminar al empleado? Ingrese \"s\" para SI o \"n\" para NO:");
				if (confirmacion == 's') {
					retorno = removeEmployee(list, len, id);
				} else if (confirmacion == 'n') {
					retorno = 2;
				}
			}
		} else {
			retorno = 2;
		}
	}
	return retorno;
}

/** \brief Elimina un empleado por ID, esta funcion es llamada por deleteEmployee
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \param id int Recibe el id del empleado a eliminar
 * \return int Devuelve 0 si realizo la eliminacion o -1 (si no encontro al empleado, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int removeEmployee(Employee *list, int len, int id) {
	int retorno = -1;
	int i;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				if (list[i].id == id) {
					list[i].isEmpty = TRUE;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Busca si hay al menos un lugar ocupado en el array
 *
 * \param list Employee* Recibe un puntero a array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve el 0 o -1 (si no hay lugar ocupado, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int getIsOccupied(Employee *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Submenu de modificaciones a un empleado del array
 *
 * \param list Employee* puntero a un array de empleados
 * \param len int largo del array de empleados
 * \return int Devuelve "0" si logro ordenar o "-1" (si el largo del array esta mal o si el puntero al array es NULL o si no encuentra al empleado)
 *
 */
int modificarEmpleado(Employee *list, int len) {
	int retorno = -1;
	int id;
	int indice;
	Employee aux;
	int opcion;
	char confirmacion;
	char cargar = 'n';

	printEmployees(list, len);
	confirmacion =
			getConfirmacion(
					"Esta seguro de continuar? presione \"s\" para SI o \"n\" para CANCELAR\n");

	if (confirmacion == 's') {
		id = getInt("\nIngrese el id del empleado a modificar: ");
		indice = findEmployeeById(list, len, id);

		if (indice != -1) {
			aux = list[indice];
			do {
				system("cls");
				opcion =
						getInt(
								"Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar apellido.\n3. Cambiar salario.\n4. Cambiar sector.\n5. Salir al menu anterior.\n");
				switch (opcion) {
				case 1:
					pedirCadena("Ingrese un nombre: ", aux.name);
					confirmacion =
							getConfirmacion(
									"\nDesea seguir ingresando datos? Ingrese \"s\" para SI o \"n\" para NO: ");
					printf("\n");
					system("pause");
					break;
				case 2:
					pedirCadena("Ingrese un apellido: ", aux.lastName);
					confirmacion =
							getConfirmacion(
									"\nDesea seguir ingresando datos? Ingrese \"s\" para SI o \"n\" para NO:");
					printf("\n");
					system("pause");
					break;
				case 3:
					aux.salary = getFloat("Ingrese el salario nuevo:");
					confirmacion =
							getConfirmacion(
									"\nDesea seguir ingresando datos? Ingrese \"s\" para SI o \"n\" para NO: ");
					printf("\n");
					system("pause");
					break;
				case 4:
					aux.sector = getInt("Ingrese el sector nuevo:");
					confirmacion =
							getConfirmacion(
									"\nDesea seguir ingresando datos? Ingrese \"s\" para SI o \"n\" para NO: ");
					printf("\n");
					system("pause");
					break;
				case 5:
					confirmacion = 'n';
					printf("\n");
					break;
				default:
					printf("Ingreso una opcion incorrecta.\n");
					printf("\n");
					system("pause");
					break;
				}
			} while (confirmacion == 's');
			printf("Este es el empleado:\n");
			printf("\n");
			showOneEmployee(aux);
			printf("\n");
			cargar =
					getConfirmacion(
							"\nDesea cargar los datos? Ingrese \"s\" para SI o \"n\" para NO:");
			if (cargar == 's') {
				list[indice] = aux;
				retorno = 1;
			} else {
				retorno = 0;
			}

		} //fin del segundo if.
	} //fin del primer if
	else {
		retorno = 0;
	}

	return retorno;
}

/** \brief Muestra un submenu de informes de salarios y opcion para ordenar la lista de empleados
 *
 * \param list Employee* puntero a un array de empleados
 * \param len int largo del array empleados
 * \return int Devuelve "0" si pudo entrar al menu "-1" (si el largo del array esta mal, si el array es NULL) o "1" si no pudo hacer el ordenamiento.
 *
 */
int informarEmpleado(Employee *list, int len) {
	int retorno = -1;
	int opcion;
	int orden;
	int opcionContinuar = 's';
	if (list != NULL && len > 0) {
		do {
			system("cls");
			printf("Ingrese una opcion: \n");
			opcion =
					getInt(
							"1. Listado de los empleados, ordenado alfabeticamente por apellido y sector.\n2. Informe de los salarios.\n3. Mostrar Empleados sin ordenar\n4. Salir al menu anterior.\n");
			switch (opcion) {
			case 1:
				orden =
						getInt(
								"\nIngrese \"1\" si desea ordenar de manera ascendente o \"0\" si desea ordenar de manera descendente:");
				if (sortEmployees(list, len, orden) != -1) {
					printEmployees(list, len);
				} else {
					retorno = 1;
				}
				printf("\n");
				system("pause");
				break;
			case 2:
				menuInformesSalarios(list, len);
				printf("\n");
				system("pause");
				break;
			case 3:
				printf("Estos son los empleados:\n");
				printEmployees(list, len);
				system("pause");
				break;
			case 4:
				opcionContinuar = 'n';
				retorno = 0;
				break;
			default:
				printf("Ingreso una opcion incorrecta.\n");
				printf("\n");
				system("pause");
				break;
			}
		} while (opcionContinuar == 's');
	}
	return retorno;
}

/** \brief Muestra por consola un submenu con informes de los salarios
 *
 * \param list Employee* puntero a un array de empleados
 * \param len int con el largo del array de empleados
 * \return void
 *
 */
void menuInformesSalarios(Employee *list, int len) {
	float salarios;
	int opcion;
	char opcionContinuar = 's';
	do {
		system("cls");
		opcion =
				getInt(
						"Ingrese una opcion:\n1.Informe del salario total.\n2.Informe del promedio de salarios.\n3.Informe de los salarios mayores al promedio.\n4.Salir al menu anterior.\n");
		switch (opcion) {
		case 1:
			salarios = getTotalSalarios(list, len);
			if (salarios == -1) {
				printf("No hay total de salarios a mostrar.\n");
			} else {
				printf("Este es el total de los salarios: %.3f\n", salarios);
			}
			printf("\n");
			system("pause");
			break;
		case 2:
			salarios = getPromedioSalarios(list, len);
			if (salarios == -1) {
				printf("No hay salario promedio a mostrar.\n");
			} else {
				printf("Este es el promedio de los salarios: %.3f\n", salarios);
			}
			printf("\n");
			system("pause");
			break;
		case 3:
			salarios = getMaximoSalario(list, len);
			if (salarios == -1) {
				printf("No hay empleados con salarios mayores al promedio.");
			}
			printf("\n");
			system("pause");
			break;
		case 4:
			opcionContinuar = 'n';
			break;
		default:
			printf("Ingreso una opcion incorrecta.\n");
			printf("\n");
			system("pause");
			break;
		}
	} while (opcionContinuar == 's');
}

/** \brief  Ordena los elementos del array de empleados, el parametro order indice "1" ascendente o "0" descendente
 *
 * \param list Employee* Puntero a un array de empleados
 * \param len int largo del array de empleados
 * \param order int "1" ascendente y "0" descendente
 * \return int Devuelve 0 si logro ordenar o -1 (si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int sortEmployees(Employee *list, int len, int order) {
	int retorno = -1;
	Employee auxEmployee;
	if (list != NULL && len > 0) {
		if (order == 1) { //criterio ascendente por param
			for (int i = 0; i < len - 1; i++) {
				for (int j = i + 1; j < len; j++) {
					if ((strcmp(list[i].lastName, list[j].lastName) > 0
							&& (list[i].sector == list[j].sector))
							|| (list[i].sector != list[j].sector
									&& list[i].sector > list[j].sector)) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
			retorno = 0;
		} else {
			if (order == 0) //criterio descendente por param
					{
				for (int i = 0; i < len - 1; i++) {
					for (int j = i + 1; j < len; j++) {
						if ((strcmp(list[i].lastName, list[j].lastName) < 0
								&& (list[i].sector == list[j].sector))
								|| (list[i].sector != list[j].sector
										&& list[i].sector < list[j].sector)) {
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
						}
					}
				}
				retorno = 0;
			}
		}
	} //fin del primer if
	return retorno;
}

/** \brief Calcula el monto total de los salarios
 *
 * \param list Employee*  puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return float Devuelte el total de los salarios
 *
 */
float getTotalSalarios(Employee *list, int len) {
	float retorno = -1;
	int i;
	float contadorSalariosTotal = 0;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				contadorSalariosTotal = list[i].salary + contadorSalariosTotal;
			}
		}
		retorno = contadorSalariosTotal;
	}
	return retorno;
}

/** \brief Calcula el promedio de los salarios
 *
 * \param list Employee* Puntero a array de empleados
 * \param len int largo del array empleados
 * \return float Devuelve el/los salario promedio o "-1" (si el largo del array esta mal, si el array es NULL o no encontro a los empleados)
 *
 */
float getPromedioSalarios(Employee *list, int len) {
	float retorno = -1;
	float acumuladorSalarios = 0;
	float contadorEmpleados = 0;
	float promedioSalarios = 0;
	int i;
	acumuladorSalarios = getTotalSalarios(list, len);
	if (list != NULL && len > 0 && acumuladorSalarios != -1) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				contadorEmpleados++;
			}
		}
		promedioSalarios = acumuladorSalarios / contadorEmpleados;
		retorno = promedioSalarios;
	}
	return retorno;
}

/** \brief Muestra los empleados con salario mayor al promedio y los muestra
 *
 * \param list Employee* Puntero a array de empleados
 * \param len int largo del array de empleados
 * \return int Devuelve "1" si encontro al menos un empleado o "-1" (si el largo del array esta mal, si el array es NULL o no encontro a NINGUN empleado con salario mayor al promedio)
 *
 */
int getMaximoSalario(Employee *list, int len) {
	int retorno = -1;
	float salarioPromedio = getPromedioSalarios(list, len);
	int i;
	if (list != NULL && len > 0) {
		if (salarioPromedio != -1) {
			for (i = 0; i < len; i++) {
				if (list[i].isEmpty == FALSE) {
					if (salarioPromedio < list[i].salary) {
						showOneEmployee(list[i]);
						retorno = 1;
					}
				}
			}
		}
	}
	return retorno;
}
