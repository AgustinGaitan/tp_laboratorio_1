/*
 * arrayEmployees.h
 *
 *  Created on: 5 may. 2020
 *      Author: Agustin Gaitan
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;


#endif /* ARRAYEMPLOYEES_H_ */



/** \brief Para indicar que todas las posiciones en el array estan vacias
 * 			esta funcion pone la bandera isEmpty en TRUE en todas las posiciones.
 *
 * \param list Employee* apunta al array de empleados
 * \param len int es la longitud del array
 * \
 * \return (-1) si hay error. (0) si esta correcto
 **/


int initEmployees(Employee* list, int len);


/**\brief añade a una lista existente de empleados los valores recibidos
 *        como parametros en la primera posicion vacia
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int return (-1) si hay error. (0) si esta bien
 */


int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/**\brief busca un empleado por Id y retorna el indice del array
 *
 *\param list Employee*
 *\param len int
 *\param id int
 *\return Retorna el indice del empleado o (-1) si hay error.
 *
 */

int findEmployeeById(Employee* list, int len, int id);



/**\brief remueve un empleado por Id (pone isEmpty en 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int return (-1) si hay error. (0) si esta correcto
 *
 */


int removeEmployee(Employee* list, int len, int id);



/**\brief ordena los elementos del array de empleados, el criterio de ordenamiento indica UP o DOWN.
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] para indicar UP - [0] indica DOWN
 * \return int return (-1) si hay error. (0) si esta correcto
 *
 */

int sortEmployees(Employee* list, int len, int order);


/**\brief muestra el contenido del array de los empleados
 *
 * \param list Employee*
 * \param lenght int
 * \return int
 *
 */

int printEmployees(Employee* list, int len);



/**\brief modifica a un empleado
 *
 * \param list Employee*
 * \param tamaño del array
 * \param sector del empleado
 * \param nombre del empleado
 * \param apellido del empleado
 * \param salario del empleado
 *
 * \return un empleado nuevo en x indice
 */


int modificarEmpleado(Employee* list, int len, int id);


/**\brief muestra a un solo empleado
 *
 * \param list Employee*
 * \param tamaño del array
 *
 * \return
 */



void printEmployee(Employee list);


/**\brief Informa el total y promedio de los empleados y cuantos superan
 * 			el salario promedio
 *
 * \param list Employee*
 * \param salario
 *
 * \return  Total y promedio de los salarios,
 * 	y cuántos empleados superan el salario promedio.
 *
 */



void salarios(Employee* list, int len);


/**\brief Busca un lugar donde guardar al empleado
 *
 * @param lista
 * @param tamaño del array
 *
 * \return indice del primer lugar vacio (isEmpty = 1)
 *
 */


int buscarEspacio(Employee* list, int len);

/**\brief Permite la carga de un empleado
 *
 * @param list lista de empleados
 * @param len longitud del array
 * @param id id del empleado a cargar
 */
void altaEmpleado(Employee* list, int len, int id);


/**\brief permite la modificacion de un empleado
 *
 * @param list lista de empleados
 * @param len longitud del array
 */

void modificarEmpleadoCarga(Employee* list, int len);


/**\brief permite la baja de un empleado
 *
 * @param list lista de empleados
 * @param len  longitud del array
 */

void bajaEmpleadoCarga(Employee* list, int len);

/**\brief permite listar a los empleados
 *
 * @param list lista de empleados
 * @param len  longitud del array
 */

void informarEmpleadoCarga(Employee* list, int len);


