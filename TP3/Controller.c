#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "menus.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	FILE* pf =  fopen(path,"r");
	system("cls");

		 if(pf != NULL)
		 {
			 parser_EmployeeFromText(pf,pArrayListEmployee); //se parsea de string a su debido tipo
			 printf("Archivo encontrado.\n\n");
			 todoOk = 0;

		 }
		 else
		 {
			 printf("Error.Archivo no encontrado\n");
		 }
		 fclose(pf);




    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	int todoOk = 1;

		FILE* pf;

		pf = fopen(path, "rb");

		if(pf != NULL)
		{
			parser_EmployeeFromBinary(pf, pArrayListEmployee);


				printf("Archivo encontrado.\n");
				todoOk = 0;

		}
		else
		{
			printf("Error. No se encontro el archivo.\n");
		}
		fclose(pf);





    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{

	int todoOk = 1;
	Employee* aux  = employee_new();


	system("cls");

	if((utn_getCadena(aux->nombre,20,3,"Ingrese el nombre del empleado: ","Error.Ingrese un nombre valido.\n") == 0))
			{

				if(employee_setNombre(aux, aux->nombre) == 0)
				{
					system("cls");
					if(utn_getEntero(&aux->horasTrabajadas, 3, "Ingrese las horas de trabajo del empleado: ", "Error. Ingrese un numero valido.\n",0,438000) == 0)
					{

						if(employee_setHorasTrabajadas(aux, aux->horasTrabajadas) == 0)
						{
							system("cls");
							if(utn_getEntero(&aux->sueldo, 3, "Ingrese el sueldo del empleado: ", "Error. Ingrese un numero valido.\n",2500,150000) == 0)
							{

								if(employee_setSueldo(aux, aux->sueldo) == 0)
								{
									system("cls");
									if(utn_getEntero(&aux->id, 3, "Ingrese el id del empleado: ", "Error. Ingrese un numero valido.\n",0,150000) == 0)
									{

										if(compareId(pArrayListEmployee, aux->id))
										{

											ll_add(pArrayListEmployee, aux);
										}
										else
										{
											printf("Id usado.\n\n");

										}


									}






								}

							}


						}





					}



				}



			}


	 return todoOk;

}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
		int auxId;
		int nuevoId;
		char nuevoNombre[20];
		int nuevasHoras;
		int nuevoSueldo;
		Employee* pEmpleado = employee_new();
		int indice = -1;
		char confirmar;
		char confirmarSwitch;

		system("cls");

			if((utn_getEntero(&auxId, 2, "Ingrese el id del empleado que quiere modificar: ", "Error. Id no encontrado\n", 0, 150000 )) == 0)
			{
				indice = findEmployeeById(pArrayListEmployee, auxId);
				printf("%d", indice);
				if(indice >= 0)
				{
					printf("Id    Nombre   Horas Trabajadas   Sueldo\n\n");
					printEmployee(pArrayListEmployee, indice);

					printf("\nConfirma la modificacion del empleado ?'s' para aceptar, 'n' para negar ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{

						do
						{

							switch(menuModificacion())
							{

								case 1:
									system("cls");
									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo id: ");
									scanf("%d", &nuevoId);
									employee_setId(pEmpleado, nuevoId);
									printf("Id modificado.\n");

									break;
								case 2:
									system("cls");
									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo nombre: ");
									fflush(stdin);
									gets(nuevoNombre);
									employee_setNombre(pEmpleado, nuevoNombre);
									printf("Nombre modificado.\n");

									break;
								case 3:
										system("cls");
										pEmpleado = ll_get(pArrayListEmployee,indice);
										printf("Ingrese las nuevas horas: ");
										scanf("%d", &nuevasHoras);
										employee_setHorasTrabajadas(pEmpleado, nuevasHoras);
										printf("Horas modificadas.\n");

									break;
								case 4:

									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo sueldo: ");
									scanf("%d", &nuevoSueldo);
									employee_setSueldo(pEmpleado, nuevoSueldo);
									printf("Sueldo modificado.\n");
									break;
								case 5:
									printf("Desea salir? 's' para salir, 'n' para quedarse: ");
									fflush(stdin);
									scanf("%c", &confirmarSwitch);
									break;
							}

							system("pause");
							system("cls");


						}while(confirmarSwitch != 's');

						employee_delete(pEmpleado);

						todoOk = 0;
					}
					else if(indice == -1)
					{
						printf("\nNo se encontro un empleado con ese id\n\n");

					}
				}

			}



    return todoOk;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

		int todoOk = 1;
	    int indice = -1;
		int auxId;
		Employee* pEmpleado = employee_new();
		char confirmar;
		system("cls");

			if((utn_getEntero(&auxId, 2, "Ingrese el id del empleado que le quiere dar de baja.\n", "Error. Id no encontrado", 0, 150000 ) == 0))
			{
				indice = findEmployeeById(pArrayListEmployee, auxId);

				if(indice >= 0)
				{
					printf("Id    Nombre   Horas Trabajadas   Sueldo\n\n");
					printEmployee(pArrayListEmployee, indice);

					printf("Confirma la baja del empleado?'s' para aceptar, 'n' para negar ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{
						ll_remove(pArrayListEmployee, indice);
						employee_delete(pEmpleado);
						printf("Baja exitosa.\n");

						todoOk = 0;
					}
				}
				else if(indice == -1)
				{
					printf("\nNo se encontro un empleado con ese id\n\n");

				}
			}




			return todoOk;
}




int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

	int todoOk = 1;
	int tam = ll_len(pArrayListEmployee);
	system("cls");

		if(pArrayListEmployee != NULL)
		{
			printf("\nId     Nombre      Horas Trabajadas    Sueldo\n\n");
			for(int i = 0; i < tam; i++)
			{

					printEmployee(pArrayListEmployee, i);

			}
		}
			else
			{
				printf("No hay empleados que mostrar.\n");
			}




    return todoOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	int orden;
	int opcion;

	system("cls");
	utn_getEntero(&opcion, 2, "Ingrese si quiere ordenar por nombre(1), o por id (2):   ", "Error. Ingrese un numero valido.\n", 1, 2);
		switch(opcion)
		{
		case 1:
			system("cls");
			utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los nombres.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

			ll_sort(pArrayListEmployee, sortEmployeeNombre, orden);
			break;
		case 2:
			system("cls");
			utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los Id.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

			ll_sort(pArrayListEmployee, sortEmployeeId,orden);
			break;

		}



		controller_ListEmployee(pArrayListEmployee);




    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;

		FILE* pf;
		int auxId;
		char auxNombre[20];
		int auxHoras;
		int auxSueldo;
		int tam = ll_len(pArrayListEmployee);
		Employee* pEmpleado;

		if(pArrayListEmployee != NULL && path != NULL)
		{
			pf = fopen(path, "w");
			if(pf != NULL)
			{

				for(int i = 0; i < tam; i++)
				{
					pEmpleado = ll_get(pArrayListEmployee, i);

					if((employee_getId(pEmpleado, &auxId)==0) &&
					   (employee_getNombre(pEmpleado, auxNombre)==0) &&
					   (employee_getHorasTrabajadas(pEmpleado, &auxHoras)==0) &&
					   (employee_getSueldo(pEmpleado, &auxSueldo)==0))
					{
						fprintf(pf, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
						todoOk = 0;
					}
				}
				fclose(pf);
				printf("Archivo de texto guardado.\n");
			}
		}

	    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
		FILE* pf;
		Employee* pEmpleado;
		int tam = ll_len(pArrayListEmployee);

		if(path != NULL && pArrayListEmployee)
		{
			pf = fopen(path, "wb");

				for(int i = 0; i < tam; i++)
				{
					pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
					fwrite(pEmpleado, sizeof(Employee), 1, pf);
				}

			printf("Archivo binario guardado.\n");
			fclose(pf);
			todoOk = 0;
		}

	    return todoOk;
}

