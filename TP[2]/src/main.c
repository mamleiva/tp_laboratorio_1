/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : Miguel Leiva 1-G
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ArrayEmployees.h"

int main(void) {

	setbuf(stdout, NULL);
	Employee lista[TAM_EM];

	showMenu(lista, TAM_EM);

	return EXIT_SUCCESS;
}
