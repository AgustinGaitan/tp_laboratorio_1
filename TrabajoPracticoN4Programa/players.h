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

/** brief Guarda un nuevo empleado en la memoria dinamica con espacios vacios
 *
 *
 *
 * return Empleado guardado en memoria dinamica
 */
ePlayer* player_new();

/** brief Se le asignan los parametros tipo string
 *
 *	param id tipo string
 *	param nombre
 *	param horas tipo string
 *	param puntos tipo string
 *
 *  return
 */


ePlayer* player_newParametros(char* idStr,char* nombreStr,char* nivelStr, char* puntosStr);


/** brief elimina un empleado de la memoria dinamica
 *
 * param empleado a eliminar
 *
 * return
 */
void player_delete(ePlayer* this);

/** brief setea el id a un empleado
 *
 * param empleado
 * param id a setear
 *
 * return si todo esta ok 0, si no 1
 *
 *
 * param empleado
 * /param id en el que se va a guardar el id obtenido
 *
 * /return si todo esta ok 0, si no 1
 *
 */

int player_getId(ePlayer* this,int* id);


/** brief setea el id a un empleado
 *
 * param empleado
 * param id a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_setId(ePlayer* this,int id);

/** brief setea el nombre a un empleado
 *
 * param empleado
 * param nombre a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */


int player_setNombre(ePlayer* this,char* nombre);

/** brief obtener el nombre de un empleado
 *
 * param empleado
 * param nombre en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int player_getNombre(ePlayer* this,char* nombre);

/** brief setea las horas trabajadas a un empleado
 *
 * param empleado
 * param horas trabajadas a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_setNivel(ePlayer* this,int nivel);


/** brief obtener las horas trabajadas de un empleado
 *
 * param empleado
 * param parametro en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_getNivel(ePlayer* this,int* nivel);

/** brief setear el puntos a un empleado
 *
 * param empleado
 * param puntos a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_setPuntos(ePlayer* this,int puntos);

/** brief obtener el puntos de un empleado
 *
 * param empleado
 * param parametro en el que se va a guardar el puntos
 *
 * return si todo esta ok 0, si no 1
 *
 */

int player_getPuntos(ePlayer* this,int* puntos);

//------------------------------------------------------------------------------------------

/** brief mostrar un empleado
 *
 * param lista
 * param indice del empleado
 *
 * return si todo esta ok 0, si no 1
 *
 */


int printPlayer(LinkedList* lista, int indice);

/** brief buscar un empleado por id
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
 * return indice del empleado
 *
 */
int compareId(LinkedList* lista, int id);

/** brief ordenar dos empleados por nombre
 *
 * param empleado x
 * param empleado y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortPlayerNombre(void* x, void* y);

/** brief ordenar dos empleados por id
 *
 * param empleado x
 * param empleado y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortPlayerId(void* x, void* y);


#endif // PLAYERS_H_INCLUDED
