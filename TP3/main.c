#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menus.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	setbuf(stdout, NULL);


	int flagTxt = 0;      //bandera para el archivo de tetxo
	int flagBin = 0;	  //bandera para el archivo binario
    char confirmar;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
            	if(flagTxt == 0 && flagBin == 0)  //para que entre solo si no se cargo el otro achivo
            	{

					if(controller_loadFromText("data.csv",listaEmpleados) == 0)
					{

						flagTxt = 1;     //si se carga el archivo de texto, la bandera cambia

					}

            	}
            	else
            	{

            		printf("Ya cargo un archivo .bin antes.\n");
            	}
                break;
            case 2:
            	if(flagTxt == 0 && flagBin == 0) //para que entre solo si no se cargo el otro achivo
                  {

            		if(controller_loadFromBinary("data.bin",listaEmpleados) == 0)
            			{

            				flagBin = 1;	//si se carga el archivo binario, la bandera cambia

            			}

                   }
            	else
            	{

            		printf("Ya cargo un archivo .csv antes.\n");

            	}
            	break;
            case 3:
            		controller_addEmployee(listaEmpleados);


            	break;
            case 4:

            		controller_editEmployee(listaEmpleados);

            	break;
            case 5:


            		controller_removeEmployee(listaEmpleados);


            	break;
            case 6:

            		controller_ListEmployee(listaEmpleados);


            	break;
            case 7:

            	    controller_sortEmployee(listaEmpleados);

            	break;
            case 8:

            	controller_saveAsText("data.csv", listaEmpleados);

            	break;
            case 9:

            	     controller_saveAsBinary("data.bin", listaEmpleados);

            	break;
            case 10:
            		printf("Desea salir? 's' para salir, 'n' para quedarse: ");
            		fflush(stdin);
            		scanf("%c", &confirmar);
            	break;
        }


        system("pause");
        system("cls");

    }while(confirmar != 's');

    ll_deleteLinkedList(listaEmpleados);


    return 0;

}
