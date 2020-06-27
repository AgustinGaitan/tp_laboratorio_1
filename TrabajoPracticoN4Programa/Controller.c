#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "players.h"
#include "parser.h"
#include "utn.h"
#include "menus.h"

int controller_loadFromText(char* path , LinkedList* pArrayPlayer) //funcion que se llama desde el main
{
	int todoOk = 1;
	FILE* pf =  fopen(path,"r");                    // se abre la file para lectura 'r'
	system("cls");

		 if(pf != NULL )
		 {
			 parser_PlayerFromText(pf,pArrayPlayer); //se parsea de string a su debido tipo
			 printf("Archivo encontrado.\n\n"); //todook
			 todoOk = 0;

		 }
		 else
		 {
			 printf("Error.Archivo no encontrado.\n");
		 }
		 fclose(pf);




    return todoOk;
}





int controller_addPlayer(LinkedList* pArrayPlayer)
{

	int todoOk = 1;
	int ultimoId;
	int ultimoIndice = ll_len(pArrayPlayer) - 1;
	ePlayer* auxDos = player_new();
	ePlayer* aux  = player_new();


	system("cls");

	auxDos = (ePlayer*) ll_get(pArrayPlayer, ultimoIndice);
	 player_getId(auxDos,&ultimoId);


	 aux->id = ultimoId+1;


	if(!(utn_getCadena(aux->nombre,20,3,"Ingrese el nombre del jugador: ","Error.Ingrese un nombre valido.\n")))
			{

				if(player_setNombre(aux, aux->nombre) == 0)
				{
					system("cls");
					if(!(utn_getEntero(&aux->nivel, 3, "Ingrese el nivel del jugador: ", "Error. Ingrese un numero valido.\n",0,250)))
					{

						if(player_setNivel(aux, aux->nivel) == 0)
						{
							system("cls");
							if(!(utn_getEntero(&aux->puntos, 3, "Ingrese el puntaje del jugador: ", "Error. Ingrese un numero valido.\n",0,150000)))
							{

								if(player_setPuntos(aux, aux->puntos) == 0)
								{
									system("cls");
									//if(!(utn_getEntero(&aux->id, 3, "Ingrese el id del jugador: ", "Error. Ingrese un numero valido.\n",0,150000)))
									//{

										if(compareId(pArrayPlayer, aux->id))
										{

											ll_add(pArrayPlayer, aux);
											player_delete(aux);
                                            //player_delete(auxDos);
										}
										else
										{
											printf("Error al asignar ID.\n\n");

										}


									//}


								}

							}


						}


					}

				}


			}


	 return todoOk;

}


int controller_editPlayer(LinkedList* pArrayPlayer)
{
	int todoOk = 1;
		int auxId;
		ePlayer* pPlayer = player_new();
		int indice = -1;
		char confirmar;
		char confirmarSwitch;

		system("cls");

			if((utn_getEntero(&auxId, 2, "Ingrese el id del jugador que quiere modificar: ", "Error. Id no encontrado\n\n", 0, 150000 )) == 0)
			{
				indice = findPlayerById(pArrayPlayer, auxId);
				//printf("%d", indice);
				if(indice >= 0)
				{
					printf("Id       Nombre          Nivel         Puntos\n\n");
					printPlayer(pArrayPlayer, indice);            //muestra al jugador que se va a modificar

					printf("Confirma la modificacion del jugador ?'s' para aceptar, 'n' para negar: ");
					fflush(stdin);
					scanf("%c", &confirmar);


					if(confirmar == 's')
					{

					    pPlayer = ll_get(pArrayPlayer,indice);

						do
						{

							switch(menuModificacion())
							{

								case 1:				//modificacion de id
									system("cls");

									utn_getEntero(&pPlayer->id, 3, "Ingrese el nuevo id del jugador: ", "Error. Ingrese un numero valido.\n\n",0,150000);

									printf("Id modificado.\n");

									break;
								case 2:              //modificacion de nombre
									system("cls");

									utn_getCadena(pPlayer->nombre,20,3,"Ingrese el nuevo nombre del jugador: ","Error.Ingrese un nombre valido.\n\n");

									printf("Nombre modificado.\n");

									break;
								case 3:                   //modificacion de nivel
										system("cls");

										utn_getEntero(&pPlayer->nivel, 3, "Ingrese el nuevo nivel del jugador: ", "Error. Ingrese un numero valido.\n\n",0,250);

										printf("Nivel modificado.\n");

									break;
								case 4:                                     //modificacion de puntaje


									utn_getEntero(&pPlayer->puntos, 3, "Ingrese la cantidad de puntos del jugador: ", "Error. Ingrese un numero valido.\n\n",0,150000);
									      //se le setea el nuevo puntaje
									printf("Puntaje modificado.\n");
									break;
								case 5:
									printf("Desea salir? 's' para salir, 'n' para quedarse: ");
									fflush(stdin);
									scanf("%c", &confirmarSwitch);
									break;
							}
							ll_set(pArrayPlayer,indice,pPlayer); //setea las modificaciones

							system("pause");
							system("cls");


						}while(confirmarSwitch != 's');

						player_delete(pPlayer);

						todoOk = 0;
					}

				}
				else if(indice == -1)
					{
						printf("\nNo se encontro un jugador con ese id\n\n");

					}

			}



    return todoOk;
}


int controller_removePlayer(LinkedList* pArrayPlayer)
{

		int todoOk = 1;
	    int indice = -1;
		int auxId;
		ePlayer* pPlayer = player_new();
		char confirmar;
		system("cls");

			if((utn_getEntero(&auxId, 2, "Ingrese el id del jugador que desea eliminar: ", "Error. Id no encontrado\n\n", 0, 150000 ) == 0))
			{
				indice = findPlayerById(pArrayPlayer, auxId);  //encuentra el indice respectivo al id ingresado

				if(indice >= 0)
				{
					printf("Id    Nombre        Nivel      Puntos\n\n");
					printPlayer(pArrayPlayer, indice);

					printf("Confirma la baja del jugador?'s' para aceptar, 'n' para negar: ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{
						ll_remove(pArrayPlayer, indice);  //se borra
						player_delete(pPlayer);  //se le saca el espacio de la memoria dinamica
						printf("Baja exitosa.\n");

						todoOk = 0;
					}
				}
				else if(indice == -1)
				{
					printf("\nNo se encontro un jugador con ese id\n\n");

				}
			}




			return todoOk;
}




int controller_ListPlayer(LinkedList* pArrayPlayer)
{

	int todoOk = 1;
	int tam = ll_len(pArrayPlayer);  //se le asigna el tamaño
	system("cls");

		if(pArrayPlayer != NULL)
		{
			printf("Id      Nombre           Nivel         Puntaje\n\n");
			for(int i = 0; i < tam; i++)
			{

					printPlayer(pArrayPlayer, i);  //muestra a los jugadores uno por uno

			}
		}
			else
			{
				printf("No hay jugadores que mostrar.\n");
			}




    return todoOk;
}


int controller_sortPlayer(LinkedList* pArrayPlayer)
{

    system("cls");
	int todoOk = 1;
	int orden;
	int opcion;
	LinkedList* pArrayPlayerCopy = ll_newLinkedList();


	if((pArrayPlayerCopy = ll_clone(pArrayPlayer)) != NULL)  //crea una copia de la lista para mostrar, ya que sino, la opcion 5 se veria afectada.
    {



        utn_getEntero(&opcion, 2, "Ingrese si quiere ordenar por nombre(1), o por id (2):   ", "Error. Ingrese un numero valido.\n", 1, 2); //eleccion
            switch(opcion)
            {
            case 1:  //primer opcion
                system("cls");
                utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los nombres.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

                ll_sort(pArrayPlayerCopy, sortPlayerNombre, orden);

                //se ordenan por nombre
                break;
            case 2:  //segunda opcion
                system("cls");
                utn_getEntero(&orden, 2, "Ingrese el orden en el que quiere que se \nacomoden los Id.Recuerde que este proceso\ntarda unos segundos. (1 ascendente o 0 descendente): ", "Error. Ingrese un numero valido\n", 0, 1);

                ll_sort(pArrayPlayerCopy, sortPlayerId,orden);

                //se ordenan por id
                break;

            }


		}



		controller_ListPlayer(pArrayPlayerCopy);

        ll_deleteLinkedList(pArrayPlayerCopy);


    return todoOk;
}





int controller_clearList(LinkedList* pArrayPlayer)
{
    system("cls");
  int todoOk = -1;
  char confirmar;

    printf("Esta seguro de que desea limpiar la lista? s/n : ");
    fflush(stdin);
    scanf("%c", &confirmar);

    if(confirmar == 's')
    {

         if(pArrayPlayer != NULL)
        {

            ll_clear(pArrayPlayer);
            printf("Lista limpia.\n\n");

            todoOk = 0;
        }
        else
        {
            printf("Error. No se pudo limpiar la lista.\n\n");
        }



    }
    else
    {

        printf("La lista quedo tal cual estaba.\n\n");
        todoOk = 0;
    }




  return todoOk;

}


int controller_createSubList(LinkedList* pArrayPlayer)
{
    system("cls");
    int todoOk = 1;
    int desde;
    int hasta;
    LinkedList* sublista;



    if(!(utn_getEntero(&desde, 2 , "Ingrese desde que Id donde desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pArrayPlayer))))
       {

           if(!(utn_getEntero(&hasta, 2 , "Ingrese hasta que Id desea crear la sublista: ", "Error. Ingrese un numero positivo o mas chico.\n\n", 0, ll_len(pArrayPlayer))))
              {

                   // desde--;
                   sublista = ll_subList(pArrayPlayer,desde,hasta);



                    controller_ListPlayer(sublista);

                    todoOk = 0;

              }
                ll_deleteLinkedList(sublista);

       }


    return todoOk;


}




int controller_insertPlayer(LinkedList* pArrayPlayer)
{
    system("cls");
    ePlayer* aux = player_new();
    int nuevoIndice;
    int nuevoIndiceMostrar;
    int todoOk = 1;


            if(!(utn_getCadena(aux->nombre,20,3,"Ingrese el nombre del jugador: ","Error.Ingrese un nombre valido.\n")))
			{

				if(player_setNombre(aux, aux->nombre) == 0)
				{
					system("cls");
					if(!(utn_getEntero(&aux->nivel, 3, "Ingrese el nivel del jugador: ", "Error. Ingrese un numero valido.\n",0,250)))
					{

						if(player_setNivel(aux, aux->nivel) == 0)
						{
							system("cls");
							if(!(utn_getEntero(&aux->puntos, 3, "Ingrese el puntaje del jugador: ", "Error. Ingrese un numero valido.\n",0,150000)))
							{

								if(player_setPuntos(aux, aux->puntos) == 0)
								{
									system("cls");
									if(!(utn_getEntero(&aux->id, 3, "Ingrese el id del jugador: ", "Error. Ingrese un numero valido.\n",0,150000)))
									{

										if(compareId(pArrayPlayer, aux->id))
										{

                                            if(!(utn_getEntero(&nuevoIndice, 3, "Ingrese en que posicion desea posicionarlo.\nTenga en cuenta que no se reemplazara el id. Simplemente se lo ubica en una posicion deseada: ", "Error. Ingrese un numero valido.\n",0,150000)))
                                            {


                                                if(!(ll_push(pArrayPlayer,nuevoIndice,aux)))
                                                {
                                                        system("cls");
                                                    nuevoIndiceMostrar = ll_indexOf(pArrayPlayer,aux);

                                                    if(ll_contains(pArrayPlayer,aux)) //valida que contenga el elemento dado
                                                       {
                                                           printf("El usuario fue ingresado exitosamente en el indice %d\n\n", nuevoIndiceMostrar);
                                                            todoOk = 0;

                                                       }
                                                       else
                                                       {


                                                           printf("Error.\n\n");
                                                       }


                                                }
                                                else
                                                {


                                                    printf("No se pudo insertar dicho jugador.\n\n");


                                                }




                                            }



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


int controller_movePlayer(LinkedList* pArrayPlayer)
{

    system("cls");
    ePlayer* aux = player_new();
    ePlayer* auxDos = player_new();
    int indice;
    int nuevoIndice;
    int todoOk = 1;

    if(!(utn_getEntero(&aux->id,3,"Ingrese el ID del jugador que desea mover: ","Error. Ingrese un ID valido",0,150000)))
    {


        indice = findPlayerById(pArrayPlayer,aux->id);

            printf("Id     Nombre         Nivel      Puntaje\n");
            printPlayer(pArrayPlayer, indice);

           auxDos = (ePlayer*) ll_pop(pArrayPlayer,indice);



           if(!(utn_getEntero(&nuevoIndice,3,"Ingrese la nueva posicion del jugador\nRecuerde que no se modifica el id:  ","Error. Ingrese una posicion valida.\n",0,ll_len(pArrayPlayer))))

           if(!(ll_push(pArrayPlayer, nuevoIndice , auxDos)))
              {


                printf("Jugador movido con exito.\n\n");
                player_delete(aux);
                player_delete(auxDos);
                todoOk = 0;

              }


    }



    return todoOk;

}
int controller_saveAsText(char* path , LinkedList* pArrayPlayer)
{
	int todoOk = 1;

		FILE* pf;
		char auxNombre[20];
		int auxId;
		int auxNivel;
		int auxPuntos;
		int tam = ll_len(pArrayPlayer); // se le asigna el tamaño
		ePlayer* pPlayer;


			pf = fopen(path, "w");                   //se abre el archivo en modo write "w"


			if(pf != NULL)
			{
                fprintf(pf,"Id,Nombre,Nivel,Puntaje\n");
				for(int i = 0; i < tam; i++)  //recorre para cada jugador
				{
					pPlayer = ll_get(pArrayPlayer, i);  //obtiene cada jugador mediante el indice

					if((player_getId(pPlayer, &auxId)==0) &&
					   (player_getNombre(pPlayer, auxNombre)==0) &&
					   (player_getNivel(pPlayer, &auxNivel)==0) &&  // si esta todo ok pasa a imprimir los jugadores
					   (player_getPuntos(pPlayer, &auxPuntos)==0))
					{

						fprintf(pf, "%d,%s,%d,%d\n", auxId, auxNombre, auxNivel, auxPuntos);  //imprime a los jugadores en el archivo
						todoOk = 0;
					}
				}
				fclose(pf);
				printf("Archivo de texto guardado.\n");
			}


	    return todoOk;
}


int controller_saveCopy(char* path ,LinkedList* pArrayPlayer)
{
    system("cls");
  	int todoOk = 1;

		FILE* pf;
		char auxNombre[20];
		int auxId;
		int auxNivel;
		int auxPuntos;
		int tam; // se le asigna el tamaño
		ePlayer* pPlayer;
        LinkedList* pArrayPlayerCopy = ll_newLinkedList();



            pArrayPlayerCopy = ll_clone(pArrayPlayer);

			pf = fopen(path, "w");                   //se abre el archivo en modo write "w"

           tam = ll_len(pArrayPlayerCopy);


           if(pArrayPlayerCopy != NULL)
           {


                    if(pf != NULL  && ll_containsAll(pArrayPlayerCopy,pArrayPlayer) )
                    {
                        fprintf(pf,"Id,Nombre,Nivel,Puntaje\n");
                        for(int i = 0; i < tam; i++)
                        {
                            pPlayer = ll_get(pArrayPlayerCopy, i);

                            if((player_getId(pPlayer, &auxId)==0) &&
                               (player_getNombre(pPlayer, auxNombre)==0) &&
                               (player_getNivel(pPlayer, &auxNivel)==0) &&  // si esta todo ok pasa a imprimir los jugadores
                               (player_getPuntos(pPlayer, &auxPuntos)==0))
                            {

                                fprintf(pf, "%d,%s,%d,%d\n", auxId, auxNombre, auxNivel, auxPuntos);  //imprime a los jugadores en el archivo
                                todoOk = 0;
                            }
                        }
                        fclose(pf);
                        printf("Copia guardada con exito .\n\n");
                        ll_deleteLinkedList(pArrayPlayerCopy);

                    }

            }
			else if(ll_containsAll(pArrayPlayerCopy,pArrayPlayer) == -1)
            {

                printf("Hubo un problema al crear el backup.\n\n");



            }


	    return todoOk;


}
