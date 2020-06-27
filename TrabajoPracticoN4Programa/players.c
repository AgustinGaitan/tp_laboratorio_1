#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"
#include "utn.h"




ePlayer* player_new()
{
	   ePlayer* nuevoPlayer = (ePlayer*) malloc(sizeof(ePlayer));

	    if(nuevoPlayer != NULL)
	    {
	      nuevoPlayer->id = 0;
	      nuevoPlayer->nivel = 0;
	      nuevoPlayer->puntos = 0;
	      strcpy(nuevoPlayer->nombre, "");

	    }



	    return nuevoPlayer;
}



ePlayer* player_newParametros(char* idStr,char* nombreStr,char* nivelStr, char* puntosStr)
{

	ePlayer* nuevoPlayer = player_new();

	if(nuevoPlayer != NULL && idStr != NULL && nombreStr != NULL && nivelStr != NULL && puntosStr != NULL)
	{
			if(player_setId(nuevoPlayer, atoi(idStr)) == 1 ||
				(player_setNombre(nuevoPlayer,nombreStr)) == 1 ||
				(player_setNivel(nuevoPlayer, atoi(nivelStr))) == 1 ||
				player_setPuntos(nuevoPlayer,atoi(puntosStr))== 1)
			{

				player_delete(nuevoPlayer);
				nuevoPlayer = NULL;

			}


	}



	return nuevoPlayer;


}

void player_delete(ePlayer* this)
{

	free(this);


}


int printPlayer(LinkedList* lista, int indice)
{
	int todoOk = 1;

		ePlayer* pPlayer;
		int auxId;
		int auxNivel;
		int auxPuntos;
		char auxNombre[20];

		if(lista != NULL && indice >= 0)
		{
			pPlayer = ll_get(lista, indice);

			if(player_getId(pPlayer, &auxId) == 0 &&
			   player_getNombre(pPlayer, auxNombre) ==0 &&
			   player_getNivel(pPlayer, &auxNivel) == 0 &&
			   player_getPuntos(pPlayer, &auxPuntos) == 0)

			{
				printf("%d    %-10s          %-3d                 %-3d\n", auxId, auxNombre, auxNivel, auxPuntos);
			}


		}
		else
		{
						printf("Error\n");
		}


	return todoOk;
}



int findPlayerById(LinkedList* lista, int id)
{
	system("cls");
	int auxId = 0;
	ePlayer* pPlayer = player_new();
	int tam = ll_len(lista);
	int indice = -1;

	for(int i = 0; i < tam; i++)
	{

		pPlayer = ll_get(lista, i);

		if(player_getId(pPlayer, &auxId) == 0)
		{
			if(auxId == id)
			{

				indice = i;
				break;

			}


		}



	}

	player_delete(pPlayer);

	return indice;

}

int compareId(LinkedList* lista, int id)
{

	int todoOk = 1;
	int auxId;
	int tam = ll_len(lista);
    ePlayer* auxPlayer = player_new();

    if( id >= 0)
    {

    	for(int i = 0; i < tam; i++)
    	{

    		auxPlayer = (ePlayer*) ll_get(lista,i);

    		player_getId(auxPlayer,&auxId);

    		if(auxId == id)
    		{

    			todoOk = 0;
    		}


    	}

    }


		return todoOk;
}

int sortPlayerNombre(void* x, void* y)
{
	int ordenDevuelto;
	char nombreUno[20];
	char nombreDos[20];

	player_getNombre(x,nombreUno);
	player_getNombre(y,nombreDos);

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

int sortPlayerId(void* x, void* y)
{

		int ordenDevuelto;
		int idUno;
		int idDos;

		player_getId(x,&idUno);
		player_getId(y,&idDos);

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
int player_setId(ePlayer* this,int id)
{
	int todoOk = 1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		todoOk = 0;

	}

	return todoOk;

}


int player_setNombre(ePlayer* this,char* nombre)
{

	int todoOk = 1;

	if(this != NULL && nombre != NULL && strlen(nombre) >= 2 && strlen(nombre) < 20)
	{
		strcpy(this->nombre, nombre);
		todoOk = 0;

	}

	return todoOk;


}

int player_setNivel(ePlayer* this,int nivel)
{
	int todoOk = 1;

	if(this != NULL && nivel >= 0)
	{

		this->nivel = nivel;
		todoOk = 0;

	}


	return todoOk;
}

int player_setPuntos(ePlayer* this,int puntos)
{
	int todoOk = 1;

	if(this != NULL && puntos > 2500)
	{

		this->puntos = puntos;
		todoOk = 0;

	}

	return todoOk;
}

//getters

int player_getId(ePlayer* this,int* id)
{
	int todoOk = 1;

	if(this != NULL && id != NULL)
	{
		*id = this -> id;
		todoOk = 0;

	}

	return todoOk;



}


int player_getNombre(ePlayer* this,char* nombre)
{

	int todoOk = 1;

		if(this != NULL && nombre != NULL)
		{
			strcpy(nombre, this->nombre);
			todoOk = 0;

		}

		return todoOk;


}

int player_getNivel(ePlayer* this,int* nivel)
{

	int todoOk = 1;

		if(this != NULL && nivel >= 0)
		{

			 *nivel = this->nivel;

			todoOk = 0;

		}


		return todoOk;

}


int player_getPuntos(ePlayer* this,int* puntos)
{

	int todoOk = 1;

		if(this != NULL && puntos != NULL)
		{

			*puntos = this->puntos;
			todoOk = 0;

		}

		return todoOk;


}
