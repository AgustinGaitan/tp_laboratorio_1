/*
 ============================================================================
 Name        : trabajoPracticoN2.c
 Author      : Agustin Gaitan
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico N2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "menus.h"
#include "utn.h"


#define TAM 1000

int main()
{
	setbuf(stdout, NULL);

	Employee lista[TAM];
	char confirmar;
	int proximoId = 999;
	int flag = 1;

	initEmployees(lista, TAM); //recorre el array para isEmpty == 1;


	do
	{

			switch(menu())
			{
				case 1:            //ALTA DE EMPLEADOS

					proximoId++;
					if(proximoId > 999 && proximoId <= 2000)
					{
					altaEmpleado(lista,TAM, proximoId);
					}

					flag = 0; //una vez que se ingresa un empleado, flag cambia a 0, permitiendo ingresar a las opciones 2,3 y 4.

					break;
				case 2:           //MODIFICAR EMPLEADO
					if(flag == 0)
					{

						modificarEmpleadoCarga(lista, TAM);
					}
					else
					{
							printf("\nDebe realizar la carga de un empleado primero.\n\n");
					}
					break;

				case 3:          //DAR DE BAJA EMPLEADO
					if(flag == 0)
					{
					    bajaEmpleadoCarga(lista, TAM);
					}
					else
					{
						printf("\nDebe realizar la carga de un empleado primero.\n\n");
					}

					break;
				case 4:	// INFORMAR
					if(flag == 0)
					{

						informarEmpleadoCarga(lista,TAM);
					}
					else
					{
						printf("\nDebe realizar la carga de un empleado primero.\n\n");
					}
					break;
				case 5:
					utn_getCaracter(&confirmar,"Seguro que quiere salir? 's' para salir, 'n' para quedarse: ","Error. Ingrese 's' o 'n'.\n",'n','s',4);
					break;


			}
			system("pause");

	}while(confirmar !='s');



}
