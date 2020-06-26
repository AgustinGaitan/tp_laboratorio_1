#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "players.h"
#include "menus.h"


int main()
{




	int flagTxt = 0;      //bandera para el archivo de tetxo
    char confirmar;
    LinkedList* listaPlayers = ll_newLinkedList();



    do{
        switch(menu())
        {
            case 1:
            	if(flagTxt == 0)  //para que entre solo si no se cargo el otro achivo
            	{

					if(controller_loadFromText("data.csv",listaPlayers) == 0)
					{

						flagTxt = 1;     //si se carga el archivo de texto, la bandera cambia

					}

            	}

                break;
            case 2:
            		controller_addPlayer(listaPlayers);


            	break;
            case 3:

            		controller_editPlayer(listaPlayers);

            	break;
            case 4:


            		controller_removePlayer(listaPlayers);


            	break;
            case 5:


                if(!ll_isEmpty(listaPlayers))
                {
            		controller_ListPlayer(listaPlayers);
                }
                else
                {

                    printf("La lista esta vacia\n\n");
                }

            	break;
            case 6:
                    if(!ll_isEmpty(listaPlayers))
                    {

                        controller_sortPlayer(listaPlayers);

                    }
                    else
                    {

                        printf("La lista esta vacia.\n\n");
                    }

            	break;
            case 7:

            	controller_saveAsText("data.csv", listaPlayers);

            	break;
            case 8:

                controller_saveCopy("dataCopia.csv",listaPlayers);

                break;
            case 9:
                  if(!ll_isEmpty(listaPlayers))
                    {

                        controller_clearList(listaPlayers);

                    }
                    else
                    {

                        printf("La lista ya está vacia.\n\n");
                    }



                break;
             case 10:
                    controller_createSubList(listaPlayers);
                break;
               case 11:
            		//controller_findPerName(listaPlayers);
            	break;
                case 12:
            		controller_insertPlayer(listaPlayers);
            	break;
            	case 13:
            		printf("Desea salir? 's' para salir, 'n' para quedarse: ");
            		fflush(stdin);
            		scanf("%c", &confirmar);
            	break;
        }


        system("pause");
        system("cls");

    }while(confirmar != 's');

    ll_deleteLinkedList(listaPlayers);


    return 0;

}
