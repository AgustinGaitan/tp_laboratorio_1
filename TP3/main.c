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


	int flagTxt = 0;
	int flagBin = 0;
    char confirmar;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
            	if(flagTxt == 0 && flagBin == 0)
            	{

					if(controller_loadFromText("data.csv",listaEmpleados) == 0)
					{

						flagTxt = 1;

					}

            	}
                break;
            case 2:
            	if(flagTxt == 0 && flagBin == 0)
                  {

            		if(controller_loadFromBinary("data.bin",listaEmpleados) == 0)
            			{

            				flagBin = 1;

            			}

                   }
            	break;
            case 3:
            	if(flagTxt || flagBin)
            	{
            		controller_addEmployee(listaEmpleados);

            	}
            	break;
            case 4:
            	if(flagTxt || flagBin)
            	{
            		controller_editEmployee(listaEmpleados);

            	}

            	break;
            case 5:
            	if(flagTxt || flagBin)
            	 {
            		controller_removeEmployee(listaEmpleados);
            	 }

            	break;
            case 6:
            	if(flagTxt || flagBin)
            	{
            		controller_ListEmployee(listaEmpleados);

            	}

            	break;
            case 7:
            	if(flagTxt || flagBin)
            	 {
            	    controller_sortEmployee(listaEmpleados);

            	}
            	break;
            case 8:
            	if(flagTxt && flagBin == 0)
            	{

            		controller_saveAsText("data.csv", listaEmpleados);
            	}
            	break;
            case 9:
            	if(flagTxt == 0 && flagBin)
            	 {

            	     controller_saveAsBinary("data.bin", listaEmpleados);
            	  }
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
    return 0;

}
