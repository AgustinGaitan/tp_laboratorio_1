


/*\brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 */



int controller_loadFromText(char* path , LinkedList* pArrayPlayer);



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_addPlayer(LinkedList* pArrayPlayer);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_editPlayer(LinkedList* pArrayPlayer);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_removePlayer(LinkedList* pArrayPlayer);


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_ListPlayer(LinkedList* pArrayPlayer);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */
int controller_sortPlayer(LinkedList* pArrayPlayer);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayPlayer);


/** \brief Crea una copia y la guarda bajo
 *
 * \param patch
 * \param array de jugadores
 * \return int
 *
 */


int controller_saveCopy(char* path , LinkedList* pArrayPlayer);






int controller_clearList(LinkedList* pArrayPlayer);




int controller_createSubList(LinkedList* pArrayPlayer);




