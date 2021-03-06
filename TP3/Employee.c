#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"




Employee* employee_new()
{
	   Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

	    if(nuevoEmpleado != NULL)
	    {
	      nuevoEmpleado->id = 0;
	      nuevoEmpleado->horasTrabajadas = 0;
	      nuevoEmpleado->sueldo = ' ';
	      strcpy(nuevoEmpleado->nombre, "");

	    }



	    return nuevoEmpleado;
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

	Employee* nuevoEmpleado = employee_new();

	if(nuevoEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
	{
			if(employee_setId(nuevoEmpleado, atoi(idStr)) == 1 ||
				(employee_setNombre(nuevoEmpleado,nombreStr)) == 1 ||
				(employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))) == 1 ||
				employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))== 1)
			{

				employee_delete(nuevoEmpleado);
				nuevoEmpleado = NULL;

			}





	}



	return nuevoEmpleado;


}

void employee_delete(Employee* this)
{

	free(this);


}


int printEmployee(LinkedList* lista, int indice)
{
	int todoOk = 1;

		Employee* pEmpleado;
		int auxId;
		int auxHoras;
		int auxSueldo;
		char auxNombre[20];

		if(lista != NULL && indice >= 0)
		{
			pEmpleado = ll_get(lista, indice);

			if(employee_getId(pEmpleado, &auxId) == 0 &&
			   employee_getNombre(pEmpleado, auxNombre) ==0 &&
			   employee_getHorasTrabajadas(pEmpleado, &auxHoras) == 0 &&
			   employee_getSueldo(pEmpleado, &auxSueldo) == 0)
			{
				printf("%d    %-10s      %-3d                 %-3d\n", auxId, auxNombre, auxHoras, auxSueldo);
			}


		}
		else
		{
						printf("Error\n");
		}


	return todoOk;
}



int findEmployeeById(LinkedList* lista, int id)
{
	system("cls");
	int auxId = 0;
	Employee* pEmpleado = employee_new();
	int tam = ll_len(lista);
	int indice = -1;

	for(int i = 0; i < tam; i++)
	{

		pEmpleado = ll_get(lista, i);

		if(employee_getId(pEmpleado, &auxId) == 0)
		{
			if(auxId == id)
			{

				indice = i;
				break;

			}


		}



	}

	employee_delete(pEmpleado);

	return indice;

}

int compareId(LinkedList* lista, int id)
{

	int todoOk = 1;
	int auxId;
	int tam = ll_len(lista);
    Employee* auxEmpleado = employee_new();

    if( id >= 0)
    {

    	for(int i = 0; i < tam; i++)
    	{

    		auxEmpleado = (Employee*) ll_get(lista,i);

    		employee_getId(auxEmpleado,&auxId);

    		if(auxId == id)
    		{

    			todoOk = 0;
    		}


    	}

    }


		return todoOk;
}

int sortEmployeeNombre(void* x, void* y)
{
	int ordenDevuelto;
	char nombreUno[20];
	char nombreDos[20];

	employee_getNombre(x,nombreUno);
	employee_getNombre(y,nombreDos);

	if(strcmp(nombreUno,nombreDos) > 0)
	{

		ordenDevuelto = 1;

	}
	else if(strcmp(nombreUno,nombreDos) < 0)
	{

		ordenDevuelto = -1;

	}



	return ordenDevuelto;
}

int sortEmployeeId(void* x, void* y)
{

		int ordenDevuelto;
		int idUno;
		int idDos;

		employee_getId(x,&idUno);
		employee_getId(y,&idDos);

		if(idUno>idDos)
		{

			ordenDevuelto = 1;

		}
		else if(idUno<idDos)
		{

			ordenDevuelto = -1;

		}



		return ordenDevuelto;



}


//setters
int employee_setId(Employee* this,int id)
{
	int todoOk = 1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		todoOk = 0;

	}

	return todoOk;

}


int employee_setNombre(Employee* this,char* nombre)
{

	int todoOk = 1;

	if(this != NULL && nombre != NULL && strlen(nombre) >= 2 && strlen(nombre) < 20)
	{
		strcpy(this->nombre, nombre);
		todoOk = 0;

	}

	return todoOk;


}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int todoOk = 1;

	if(this != NULL && horasTrabajadas >= 0)
	{

		this->horasTrabajadas = horasTrabajadas;
		todoOk = 0;

	}


	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int todoOk = 1;

	if(this != NULL && sueldo > 2500)
	{

		this->sueldo = sueldo;
		todoOk = 0;

	}

	return todoOk;
}

//getters

int employee_getId(Employee* this,int* id)
{
	int todoOk = 1;

	if(this != NULL && id != NULL)
	{
		*id = this -> id;
		todoOk = 0;

	}

	return todoOk;



}


int employee_getNombre(Employee* this,char* nombre)
{

	int todoOk = 1;

		if(this != NULL && nombre != NULL)
		{
			strcpy(nombre, this->nombre);
			todoOk = 0;

		}

		return todoOk;


}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

	int todoOk = 1;

		if(this != NULL && horasTrabajadas >= 0)
		{

			 *horasTrabajadas = this->horasTrabajadas;

			todoOk = 0;

		}


		return todoOk;

}


int employee_getSueldo(Employee* this,int* sueldo)
{

	int todoOk = 1;

		if(this != NULL && sueldo != NULL)
		{

			*sueldo = this->sueldo;
			todoOk = 0;

		}

		return todoOk;


}
