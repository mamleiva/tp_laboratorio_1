/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : Miguel Leiva 1-G
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
*/
#include "ArrayEmployees.h"

int main(void) {

	setbuf(stdout, NULL);
	Employee lista[1000];

	showMenu(lista, 1000);

	return EXIT_SUCCESS;
}
