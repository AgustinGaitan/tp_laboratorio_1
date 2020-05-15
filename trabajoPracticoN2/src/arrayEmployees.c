/*
 * arrayEmployees.c
 *
 *  Created on: 5 may. 2020
 *      Author: Agustin Gaitan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "menus.h"
#include "utn.h"


int initEmployees(Employee* list, int len)
{
	int retorno = -1;

	if(list != NULL)
	{
		for(int i = 0; i < len; i++)    //recorre el vector e inicializa el valor isEmpty en 1.
		{
			list[i].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}


int findEmployeeById(Employee* list, int len, int id)
{
	int indice = -1;

	for(int i = 0; i < len; i++)
	{
		if( list[i].id == id )       // Busca si el id ingresado es igual al id del array
		{
			indice = i;
			break;
		}

	}

	return indice;
}


int buscarEspacio(Employee* list, int len)
{
	int indice = -1;

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty)         //Recorre el array buscando un isEmpty 1, una vez que lo encuentra indice toma el valor de i y lo retorna.
			{
				indice = i;
				break;
			}

		}

	return indice;
}

void altaEmpleado(Employee* list, int len,int id)
{
	int auxId;
	char nombre[51];
	char apellido[51];
	float salario = 0;
	int sector = 0;
					system("cls");
					printf("****Alta de empleados****\n\n");
					utn_getCadena(nombre,51,4,"Ingrese el nombre del empleado: ","Error. Ingrese un nombre valido.\n");
					utn_getCadena(apellido,51,4,"Ingrese el apellido del empleado: ","Error. Ingrese un apellido valido.\n");
					utn_getFlotante(&salario, 4, "Ingrese el salario del empleado: ", "Error.Ingrese un salario valido\n", 2000, 80000);
					utn_getEntero(&sector, 4,"Ingrese el sector del empleado(1-5): ","Error. Ingrese un sector valido\n",1,5);
					auxId = id;

					addEmployee(list, len, auxId, nombre, apellido, salario, sector);

}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	system("cls");
	int retorno = -1;
	int indice = buscarEspacio(list,len);
	Employee auxEmpleado;

		if(indice == -1 && list == NULL) //ya que no existen indices negativos, si es distinto de -1 entra en el else y copia los nombres ingresados al auxiliar
		{
			printf("No hay lugar en el sistema.\n");
		}
		else
		{
			strcpy(auxEmpleado.name, name);
			strcpy(auxEmpleado.lastName, lastName);
			auxEmpleado.id = id;
			auxEmpleado.salary = salary;
			auxEmpleado.sector = sector;
			auxEmpleado.isEmpty = 0;
			list[indice] = auxEmpleado;   //el auxiliar de tipo Employee pasa los datos a list
			retorno = 0;

		}



	return retorno;
}

void printEmployee(Employee list) //muestra un solo empleado
{

	printf("%d        %-10s         %-10s         %2.f         %5d\n", list.id, list.name, list.lastName, list.salary, list.sector);


}
void informarEmpleadoCarga(Employee* list, int len)
{

	int orden;


		system("cls");
		printf("**** Informe ****\n\n");
		printf("Los empleados van a ser ordenados por sector y apellido.\n");
		utn_getEntero(&orden,4,"Ingrese en que orden desea listarlos ('1' para ascendente, '0' para descendente) : ","Error. Ingrese un orden valido.\n",0,1);
		printf("**Apellidos y sectores ordenados**\n");

		sortEmployees(list, len, orden);          //Ordena los empleados
		printEmployees(list, len);					//Muestra a los empleados ordenados


		salarios(list,len);					//Muestra el total y promedio de los salarios. Ademas muestra cuantos empleados superan el salario promedio.



}
int printEmployees(Employee* list, int len)
{
	int retorno = -1;
	system("cls");
	printf("***** Lista de empleados *****\n\n\n");
	printf("Id        Nombre          Apellido            Salario        Sector\n\n");

	for(int i = 0; i< len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printEmployee(list[i]); //muestra a los empleados cargados en el indice i
			printf("\n\n");
			retorno = 0;
		}
	}//HACER FUNCION PRINT EMPLOYEE


	return retorno;
}


int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	Employee aux;

	for(int i = 0; i < len -1; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(order == 1 && list[i].isEmpty == 0 && list[j].isEmpty == 0)	//si order es 1 ascendente
			{

					if(list[i].sector > list[j].sector)       //ascendente
						{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
						}
						else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0)
						{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;

						}

			}
			else if (order == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)  // si order es 0,  descendente
			{


					if (list[i].sector < list[j].sector)
					{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;

					}
				else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0)
					{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
					}
			}
			retorno = 0;
		}
	}//fin del for principal




	return retorno;
}


void salarios(Employee* list, int len)
{

	float totalSalarios = 0;
	float promedioSalarios = 0;
	int  contadorEmpleados = 0;
	int contadorEmpleadosMayorPromedio = 0;


	for(int i = 0 ; i< len; i++)  //recorre el array en busca de isEmpty == 0,  acumula los salarios y cuenta los empleados.
	{

		if(list[i].isEmpty == 0)
		{
			totalSalarios += list[i].salary;
			 contadorEmpleados++;
		}
	}


	promedioSalarios =  totalSalarios/ (float) contadorEmpleados ; //promedio de salarios

	for(int i = 0; i < len; i++) //recorre el array en busca de isEmpty == 0, y si el salario de alguno de los empleados es mayor al promedio, el contador aumenta 1.
	{
		if(list[i].isEmpty==0)
		{
			if(list[i].salary > promedioSalarios)
			{
				contadorEmpleadosMayorPromedio++;
			}

		}
	}
	printf("El total de los salarios es: %2.f\n\n", totalSalarios);
	printf("El promedio de los salarios es: %2.f\n\n", promedioSalarios);
	printf("La cantidad de empleados con un salario mayor al promedio es %d\n\n ", contadorEmpleadosMayorPromedio);





}

void modificarEmpleadoCarga(Employee* list, int len)
{
	int  idBuscar;
	int indice;

			system("cls");
			utn_getEntero(&idBuscar,4,"Ingrese el ID del empleado que desea modificar: ","Error. Ingrese un ID valido.\n",1000,2000);
			indice = findEmployeeById(list,len,idBuscar);
			if(indice == -1 && list == NULL)
			{
				printf("Error. Id Incorrecto.\n\n");

			}
			else
			{
			for (int i = 0; i < len; i++)
				{
					if(i == indice)
					{
						modificarEmpleado(list,len,idBuscar);
						break;
					}
				}
			} //fin del else.
}

int modificarEmpleado(Employee* list, int len, int id)
{
	system("cls");
		int retorno = -1;
		int indice = findEmployeeById(list,len,id);
		char confirma;
		char confirmaSalida;
		Employee nuevoEmpleado;



			if(indice == -1 && list == NULL)
			{
				printf("\nNo se encontro al empleado que quizo buscar\n");
			}
			else if (indice >= 0 && list[indice].isEmpty == 0) //se cambian los nombres por los nuevos modificados siempre y cuando el usuario ingrese 's'
			{
				printf("El nombre del empleado con ese ID es: %s\n", list[indice].name);
				printf("El apellido del empleado con ese ID es: %s\n", list[indice].lastName);
				printf("El salario del empleado con ese ID es: %2.f\n", list[indice].salary);
				printf("El sector del empleado con ese ID es: %d\n", list[indice].sector);

				printf("\n\n\n");

				utn_getCaracter(&confirma,"Seguro que quiere modificar este empleado? 's' / 'n' : ","Error. Ingrese 's' o 'n'.\n",'n','s',4);

				if(confirma == 's')
				{
					do
					{
						switch(menuModificar())
						{
							case 1:
								utn_getCadena(nuevoEmpleado.name,51,4,"Ingrese el nuevo nombre del empleado: ","Error. Ingrese un nombre valido.\n");
								strcpy(list[indice].name, nuevoEmpleado.name);
								break;
							case 2:
								utn_getCadena(nuevoEmpleado.lastName,51,4,"Ingrese el nuevo apellido del empleado: ","Error. Ingrese un apellido valido.\n");
								strcpy(list[indice].lastName,nuevoEmpleado.lastName);

								break;
							case 3:
								utn_getFlotante(&nuevoEmpleado.salary, 4, "Ingrese el nuevo salario del empleado: ", "Error.Ingrese un salario valido\n", 2000, 80000);
								 list[indice].salary = nuevoEmpleado.salary;
								break;
							case 4:
								utn_getEntero(&nuevoEmpleado.sector, 4,"Ingrese el nuevo sector del empleado(1-5): ","Error. Ingrese un sector valido\n",1,5);
								 list[indice].sector = nuevoEmpleado.sector;
								break;
							case 5:
								utn_getCaracter(&confirmaSalida,"Seguro que quiere salir? 's' para salir, 'n' para quedarse: ","Error. Ingrese 's' o 'n'.\n",'n','s',4);
								break;

						}

					}while(confirmaSalida != 's');


					nuevoEmpleado.id = list[indice].id;
					nuevoEmpleado.isEmpty = list[indice].isEmpty;

					retorno = 0;
				}
			}

	return retorno;
}

void bajaEmpleadoCarga(Employee* list, int len)
{

	int  idBuscar;



		system("cls");
		utn_getEntero(&idBuscar,4,"Ingrese el ID del empleado que desea modificar: ","Error. Ingrese un ID valido.\n",1000,2000);
		removeEmployee(list, len, idBuscar);



}




int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int indice = findEmployeeById(list,len,id); //busca el empleado
	char confirma;

				if(indice == -1 && list == NULL)
				{
					printf("\nError. ID incorrecto\n\n");
				}
				else
				{
					printf("El nombre del empleado con ese ID es: %s\n", list[indice].name);
					printf("El apellido del empleado con ese ID es: %s\n", list[indice].lastName);
					printf("El salario del empleado con ese ID es: %2.f\n", list[indice].salary);
					printf("El sector del empleado con ese ID es: %d\n", list[indice].sector);

					printf("\n\n\n");
					utn_getCaracter(&confirma,"Seguro que quiere borrar este empleado? 's' / 'n' : ","Error. Ingrese 's' o 'n'.\n",'n','s',4);


					if(confirma == 's')
					{
						list[indice].isEmpty = 1;  //Cambia el campo isEmpty a 1
						printf("Empleado removido con exito.\n\n");
					}

					retorno = 0;

				}




	return retorno;
}

