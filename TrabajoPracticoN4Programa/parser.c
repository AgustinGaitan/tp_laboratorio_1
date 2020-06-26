#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "players.h"


int parser_PlayerFromText(FILE* pFile , LinkedList* pArrayPlayer)
{
	int todoOk = 1;
	ePlayer* pPlayer;

	char auxiliarId[10000];
	char auxiliarNombre[20];
	char auxiliarNivel[1000];
	char auxiliarPuntaje[100];
	int cant;



		//fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarNivel, auxiliarPuntaje);

	do
	{

		cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxiliarId, auxiliarNombre, auxiliarNivel, auxiliarPuntaje);
		if(cant == 4)
		{

			pPlayer = player_newParametros(auxiliarId, auxiliarNombre, auxiliarNivel, auxiliarPuntaje); //le pasa los parametros.

			if(pPlayer != NULL)
			{

				ll_add(pArrayPlayer, pPlayer);
				todoOk = 0;

			}

		}


	}while(!feof(pFile));



    return todoOk;
}



