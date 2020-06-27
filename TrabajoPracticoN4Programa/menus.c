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


	printf("Bienvenido al sistema de almacenamiento de datos\nde jugadores de Linked List: the game\n\n");


	printf("1. Cargar los datos de jugadores desde\n el archivo data.csv.\n");
	printf("2. Agregar jugador.\n");
	printf("3.Modificar datos de jugador.\n");
	printf("4. Eliminar jugador.\n");
	printf("5. Listar jugadores\n");
	printf("6. Ordenar jugadores\n");
	printf("7. Insertar jugador.\n");
	printf("8. Mover Jugador\n");
	printf("9. Limpiar lista.\n");
	printf("10. Crear sublista de nombres\n");
	printf("11. Guardar los datos de los jugadores en un archivo  .csv\n");
	printf("12. Guardar una copia del archivo, se llamara ''dataCopia.csv''\n");
	printf("13. Salir\n");


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
	printf("3. Modificar Nivel.\n");
	printf("4. Modificar Puntos.\n");
	printf("5. Salir.\n");



	printf("Ingrese la opcion que desee: ");
	scanf("%d", &opcion);

	return opcion;


}



