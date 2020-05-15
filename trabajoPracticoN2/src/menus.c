/*
 * menus.c
 *
 *  Created on: 9 may. 2020
 *      Author: Agustin Gaitan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "menus.h"
#include "utn.h"


int menu()
{
	int opcion;

	system("cls");

	printf("***** Menu *****\n\n");

	printf("1.Dar de alta a un empleado.\n");
	printf("2.Modificar a un empleado.\n");
	printf("3.Dar de baja a un empleado.\n");
	printf("4.Informar.\n");
	printf("5.Salir.\n\n");


	utn_getEntero(&opcion, 4,"Ingrese la opcion que desea: ","Error. Ingrese un numero valido.\n",1,5);

	return opcion;

}




int menuModificar()
{

	int opcion;

		system("cls");

		printf("***** Menu de modificacion *****\n\n");

		printf("1.Cambiar el nombre.\n");
		printf("2.Cambiar el apellido.\n");
		printf("3.Cambiar el salario.\n");
		printf("4.Cambiar el sector.\n");
		printf("5.Salir.\n\n");


		utn_getEntero(&opcion, 4,"Ingrese la opcion que desea: ","Error. Ingrese un numero valido.\n",1,5);

		return opcion;

}




