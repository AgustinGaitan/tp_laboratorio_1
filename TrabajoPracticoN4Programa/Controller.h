


/*\brief Carga los datos de los jugadores desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 */



int controller_loadFromText(char* path , LinkedList* pArrayPlayer);



/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_addPlayer(LinkedList* pArrayPlayer);

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_editPlayer(LinkedList* pArrayPlayer);

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_removePlayer(LinkedList* pArrayPlayer);


/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */

int controller_ListPlayer(LinkedList* pArrayPlayer);

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */
int controller_sortPlayer(LinkedList* pArrayPlayer);


/** \brief Guarda los datos de los jugadores en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayPlayer);


/** \brief Crea una copia y la guarda bajo el nombre "dataCopia.csv"
 *
 * \param patch
 * \param array de jugadores
 * \return int
 *
 */


int controller_saveCopy(char* path , LinkedList* pArrayPlayer);




/** \brief Limpia la lista
 *
 *
 * \param array de jugadores
 * \return int
 *
 */

int controller_clearList(LinkedList* pArrayPlayer);


/** \brief Crea una sublista
 *
 *
 * \param array de jugadores
 * \return int
 *
 */

int controller_createSubList(LinkedList* pArrayPlayer);


/** \brief Inserta un jugador en un indice a ingresar
 *
 *
 * \param array de jugadores
 * \return int
 *
 */

int controller_insertPlayer(LinkedList* pArrayPlayer);

/** \brief Mueve un jugador en un indice a seleccionar
 *
 *
 * \param array de jugadores
 * \return int
 *
 */

int controller_movePlayer(LinkedList* pArrayPlayer);







