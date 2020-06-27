/*
 * parser.h
 *
 *  Created on: 12 jun. 2020
 *      Author: Agustin Gaitan
 */

#ifndef PARSER_H_
#define PARSER_H_


/** \brief Parsea los datos los datos de los jugadores desde el archivo data.csv
 *
 * \param path char*
 * \param pArrayPlayer LinkedList*
 * \return int
 *
 */
int parser_PlayerFromText(FILE* pFile , LinkedList* pArrayPlayer);





#endif /* PARSER_H_ */
