#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "menus.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) //funcion que se llama desde el main
{
	int todoOk = 1;
	FILE* pf =  fopen(path,"r");                    // se abre la file para lectura 'r'
	system("cls");

		 if(pf != NULL)
		 {
			 parser_EmployeeFromText(pf,pArrayListEmployee); //se parsea de string a su debido tipo
			 printf("Archivo encontrado.\n\n"); //todook
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
	system("cls");


		FILE* pf = fopen(path, "rb"); // se abre el archivo con opcion read binary "rb"





		if(pf != NULL)
		{
			parser_EmployeeFromBinary(pf, pArrayListEmployee);       //se parsea


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
				//printf("%d", indice);
				if(indice >= 0)
				{
					printf("Id    Nombre   Horas Trabajadas   Sueldo\n\n");
					printEmployee(pArrayListEmployee, indice);            //muestra al empleado que se va a modificar

					printf("\nConfirma la modificacion del empleado ?'s' para aceptar, 'n' para negar ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{

						do
						{

							switch(menuModificacion())
							{

								case 1:				//modificacion de id
									system("cls");
									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo id: ");
									scanf("%d", &nuevoId);
									employee_setId(pEmpleado, nuevoId);  //se setea el nuevo id
									printf("Id modificado.\n");

									break;
								case 2:              //modificacion de nombre
									system("cls");
									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo nombre: ");
									fflush(stdin);
									gets(nuevoNombre);
									employee_setNombre(pEmpleado, nuevoNombre);  //se le setea el nuevo nombre
									printf("Nombre modificado.\n");

									break;
								case 3:                   //modificacion de horas
										system("cls");
										pEmpleado = ll_get(pArrayListEmployee,indice);
										printf("Ingrese las nuevas horas: ");
										scanf("%d", &nuevasHoras);
										employee_setHorasTrabajadas(pEmpleado, nuevasHoras);     //se le setean las nuevas horas
										printf("Horas modificadas.\n");

									break;
								case 4:                                     //modificacion de sueldo

									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo sueldo: ");
									scanf("%d", &nuevoSueldo);
									employee_setSueldo(pEmpleado, nuevoSueldo);       //se le setea el nuevo sueldo
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

			if((utn_getEntero(&auxId, 2, "Ingrese el id del empleado que le quiere dar de baja: \n", "Error. Id no encontrado", 0, 150000 ) == 0))
			{
				indice = findEmployeeById(pArrayListEmployee, auxId);  //encuentra el indice respectivo al id ingresado

				if(indice >= 0)
				{
					printf("Id    Nombre   Horas Trabajadas   Sueldo\n\n");
					printEmployee(pArrayListEmployee, indice);

					printf("Confirma la baja del empleado?'s' para aceptar, 'n' para negar ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{
						ll_remove(pArrayListEmployee, indice);  //se borra
						employee_delete(pEmpleado);  //se le saca el espacio de la memoria dinamica
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
	int tam = ll_len(pArrayListEmployee);  //se le asigna el tamaño
	system("cls");

		if(pArrayListEmployee != NULL)
		{
			printf("Id     Nombre      Horas Trabajadas    Sueldo\n\n");
			for(int i = 0; i < tam; i++)
			{

					printEmployee(pArrayListEmployee, i);  //muestra a los empleados uno por uno

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
	utn_getEntero(&opcion, 2, "Ingrese si quiere ordenar por nombre(1), o por id (2):   ", "Error. Ingrese un numero valido.\n", 1, 2); //eleccion
		switch(opcion)
		{
		case 1:  //primer opcion
			system("cls");
			utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los nombres.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

			ll_sort(pArrayListEmployee, sortEmployeeNombre, orden);

			//se ordenan por nombre
			break;
		case 2:  //segunda opcion
			system("cls");
			utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los Id.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

			ll_sort(pArrayListEmployee, sortEmployeeId,orden);

			//se ordenan por id
			break;

		}



		controller_ListEmployee(pArrayListEmployee);




    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;

		FILE* pf;
		char auxNombre[20];
		int auxId;
		int auxHoras;
		int auxSueldo;
		int tam = ll_len(pArrayListEmployee); // se le asigna el tamaño
		Employee* pEmpleado;


			pf = fopen(path, "w");                   //se abre el archivo en modo write "w"


			if(pf != NULL)
			{

				for(int i = 0; i < tam; i++)  //recorre para cada empleado
				{
					pEmpleado = ll_get(pArrayListEmployee, i);  //obtiene cada empleado mediante el indice

					if((employee_getId(pEmpleado, &auxId)==0) &&
					   (employee_getNombre(pEmpleado, auxNombre)==0) &&
					   (employee_getHorasTrabajadas(pEmpleado, &auxHoras)==0) &&  // si esta todo ok pasa a imprimir los empleados
					   (employee_getSueldo(pEmpleado, &auxSueldo)==0))
					{

						fprintf(pf, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);  //imprime a los empleados en el archivo
						todoOk = 0;
					}
				}
				fclose(pf);
				printf("Archivo de texto guardado.\n");
			}


	    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
		FILE* pf;
		Employee* pEmpleado;
		int tam = ll_len(pArrayListEmployee); //tamaño


			pf = fopen(path, "wb");      //abre el archivo con opcion de escritura

				for(int i = 0; i < tam; i++) //recorre a los empleados con intencion de escribirlos
				{
					pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
					fwrite(pEmpleado, sizeof(Employee), 1, pf);          //los escribe


				}

				printf("Archivo binario guardado.\n");

			fclose(pf); //se cierra el archivo


			todoOk = 0;


	    return todoOk;
}

