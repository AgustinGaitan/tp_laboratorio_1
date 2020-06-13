#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** brief Guarda un nuevo empleado en la memoria dinamica con espacios vacios
 *
 *
 *
 * return Empleado guardado en memoria dinamica
 */
Employee* employee_new();

/** brief Se le asignan los parametros tipo string
 *
 *	param id tipo string
 *	param nombre
 *	param horas tipo string
 *	param sueldo tipo string
 *
 *  return
 */


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** brief elimina un empleado de la memoria dinamica
 *
 * param empleado a eliminar
 *
 * return
 */
void employee_delete(Employee* this);

/** brief setea el id a un empleado
 *
 * param empleado
 * param id a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int employee_setId(Employee* this,int id);

/** brief obtener el id de un empleado
 *
 * param empleado
 * param id en el que se va a guardar el id obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_getId(Employee* this,int* id);

/** brief setea el nombre a un empleado
 *
 * param empleado
 * param nombre a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int employee_setNombre(Employee* this,char* nombre);

/** brief obtener el nombre de un empleado
 *
 * param empleado
 * param nombre en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** brief setea las horas trabajadas a un empleado
 *
 * param empleado
 * param horas trabajadas a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** brief obtener las horas trabajadas de un empleado
 *
 * param empleado
 * param parametro en el que se va a guardar el nombre obtenido
 *
 * return si todo esta ok 0, si no 1
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** brief setear el sueldo a un empleado
 *
 * param empleado
 * param sueldo a setear
 *
 * return si todo esta ok 0, si no 1
 *
 */

int employee_setSueldo(Employee* this,int sueldo);

/** brief obtener el sueldo de un empleado
 *
 * param empleado
 * param parametro en el que se va a guardar el sueldo
 *
 * return si todo esta ok 0, si no 1
 *
 */

int employee_getSueldo(Employee* this,int* sueldo);

//------------------------------------------------------------------------------------------

/** brief mostrar un empleado
 *
 * param lista
 * param indice del empleado
 *
 * return si todo esta ok 0, si no 1
 *
 */


int printEmployee(LinkedList* lista, int indice);

/** brief buscar un empleado por id
 *
 * param lista
 * param id a buscar
 *
 * return si todo esta ok 0, si no 1
 *
 */

int findEmployeeById(LinkedList* lista, int id);

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
int sortEmployeeNombre(void* x, void* y);

/** brief ordenar dos empleados por id
 *
 * param empleado x
 * param empleado y
 *
 * return si todo esta ok 0, si no 1
 *
 */
int sortEmployeeId(void* x, void* y);


#endif // employee_H_INCLUDED
