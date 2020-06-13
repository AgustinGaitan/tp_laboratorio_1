#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	Employee* pEmpleado;

	char auxiliarId[10000];
	char auxiliarNombre[20];
	char auxiliarHoras[1000];
	char auxiliarSueldo[100];
	int cant;



		//fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarHoras, auxiliarSueldo);

	do
	{

		cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarHoras, auxiliarSueldo);
		if(cant == 4)
		{

			pEmpleado = employee_newParametros(auxiliarId, auxiliarNombre, auxiliarHoras, auxiliarSueldo); //le pasa los parametros.

			if(pEmpleado != NULL)
			{

				ll_add(pArrayListEmployee, pEmpleado);
				todoOk = 0;

			}

		}


	}while(!feof(pFile));



    return todoOk;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;

		Employee* pEmployee;

		if(pFile != NULL)
		{
			do
			{
				pEmployee = employee_new(); // se busca espacio




				if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
				{
					ll_add(pArrayListEmployee, pEmployee);
					todoOk = 0;
				}
			}while(!feof(pFile));
		}




    return todoOk;
}
