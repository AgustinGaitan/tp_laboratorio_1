/*
 * menus.c
 *
 *  Created on: 11 jun. 2020
 *      Author: Agustin Gaitan
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "utn.h"


int menu()
{

	int opcion;
	system("cls");


	printf("****Menu principal****\n\n");

	printf("1. Cargar los datos de los empleados desde\n el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los empleados desde\n el archivo data.csv (modo binario).\n");
	printf("3. Alta de empleado.\n");
	printf("4.Modificar datos de empleado.\n");
	printf("5. Baja de empleado.\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n");
	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");

	printf("Ingrese la opcion que desee: ");
	scanf("%d", &opcion);

	return opcion;

}



int menuModificacion()
{
	int opcion;
	system("cls");


	printf("****Menu de modificacion****\n\n");

	printf("1. Modificar Id\n");
	printf("2. Modificar nombre.\n");
	printf("3. Modificar horas trabajadas.\n");
	printf("4. Modificar sueldo.\n");
	printf("5. Salir.\n");



	printf("Ingrese la opcion que desee: ");
	scanf("%d", &opcion);

	return opcion;


}



