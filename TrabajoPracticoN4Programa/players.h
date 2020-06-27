#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int nivel;
    int puntos;
}ePlayer;

/** brief Guarda un nuevo jugador en la memoria dinamica con espacios vacios
 *
 *
 *
 * return jugador guardado en memoria dinamica
 */
ePlayer* player_new();

/** brief Se le asignan los parametros tipo string
 *
 *	param id tipo string
 *	param nombre
 *	param nivel string
 *	param puntos tipo string
 *
 *  return
 */


ePlayer* player_newParametros(char* idStr,char* nombreStr,char* nivelStr, char* puntosStr);


/** brief elimina un jugador de la memoria dinamica
 *
 * param jugador a eliminar
 *
 * return
 */
void player_delete(ePlayer* this);

/** brief setea el id a un jugador
 *
 * param jugador
 * param id a setear
 *
 * return si todo esta ok 0, si no 1
 *
 *
 * param jugador
 * /param id en el que se va a guardar el id obtenido
 *
 * /return si todo esta ok 0, si no 1
 *
 */

int player_getId(ePlayer* this,int* id);


/** brief setea el id a un jugador
 *
 * param jugador
 * param id a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_setId(ePlayer* this,int id);

/** brief setea el nombre a un jugador
 *
 * param jugador
 * param nombre a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */


int player_setNombre(ePlayer* this,char* nombre);

/** brief obtener el nombre de un jugador
 *
 * param jugador
 * param nombre en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int player_getNombre(ePlayer* this,char* nombre);

/** brief setea las horas trabajadas a un jugador
 *
 * param jugador
 * param nivel a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_setNivel(ePlayer* this,int nivel);


/** brief obtener las horas trabajadas de un jugador
 *
 * param jugador
 * param parametro en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_getNivel(ePlayer* this,int* nivel);

/** brief setear el puntos a un jugador
 *
 * param jugador
 * param puntos a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_setPuntos(ePlayer* this,int puntos);

/** brief obtener el puntos de un jugador
 *
 * param jugador
 * param parametro en el que se va a guardar los puntos
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_getPuntos(ePlayer* this,int* puntos);

//------------------------------------------------------------------------------------------

/** brief mostrar un jugador
 *
 * param lista
 * param indice del jugador
 *
 * return si todo esta ok 0, si no 1
 *
 */


int printPlayer(LinkedList* lista, int indice);

/** brief buscar un jugador por id
 *
 * param lista
 * param id a buscar
 *
 * return si todo esta ok 0, si no 1
 *
 */

int findPlayerById(LinkedList* lista, int id);

/** brief comparar IDs para usar en el alta, baja y modificar
 *
 * param lista
 * param id a comparar dentro de la funcion con un auxiliar
 *
 * return indice del jugador
 *
 */
int compareId(LinkedList* lista, int id);

/** brief ordenar dos jugadores por nombre
 *
 * param jugador x
 * param jugador y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortPlayerNombre(void* x, void* y);

/** brief ordenar dos jugadores por id
 *
 * param jugador x
 * param jugador y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortPlayerId(void* x, void* y);


#endif // PLAYERS_H_INCLUDED
