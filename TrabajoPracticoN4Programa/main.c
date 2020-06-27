#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "players.h"
#include "menus.h"


int main()
{





    char confirmar;
    LinkedList* listaPlayers = ll_newLinkedList();



    do{
        switch(menu())
        {
            case 1:



					controller_loadFromText("data.csv",listaPlayers);


                break;
            case 2:

            		controller_addPlayer(listaPlayers);


            	break;
            case 3:
                    if(!ll_isEmpty(listaPlayers))
                    {
            		controller_editPlayer(listaPlayers);
                    }
                else
                {

                    printf("La lista esta vacia\n\n");
                }

            	break;
            case 4:

                    if(!ll_isEmpty(listaPlayers))
                    {
            		controller_removePlayer(listaPlayers);
                    }
                    else
                    {

                        printf("La lista esta vacia\n\n");
                    }


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

                if(!ll_isEmpty(listaPlayers))
                    {
                        controller_insertPlayer(listaPlayers);
                    }
                    else
                    {

                        printf("La lista esta vacia.\n\n");
                    }

            	break;
            case 8:
                    if(!ll_isEmpty(listaPlayers))
                    {
                        controller_movePlayer(listaPlayers);
                    }
                    else
                    {

                        printf("La lista esta vacia.\n\n");
                    }

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
                 if(!ll_isEmpty(listaPlayers))
                    {
                    controller_createSubList(listaPlayers);
                    }
                    else
                    {

                        printf("La lista está vacia.\n\n");
                    }


                break;
               case 11:
                        controller_saveAsText("data.csv", listaPlayers);
            	break;
                case 12:
                        controller_saveCopy("dataCopia.csv",listaPlayers);
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
