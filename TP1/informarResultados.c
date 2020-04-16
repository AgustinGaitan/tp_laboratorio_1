#include <stdio.h>
#include <stdlib.h>
#include "informarResultados.h"

/** \brief Informa los resultados
 *
 * \param  entero a, que sera el primer operando
 * \param  entero b, que sera el segundo operando
  * \param entero c, que sera el resultado
 *
 */
#

void mostarSuma(int a,int b, int c)
{
    printf("\nEl resultado de %d + %d es: %d ", a, b, c);
}

void mostrarResta(int a,int b, int c)
{
     printf("\n\nEl resultado de %d - %d es: %d ", a, b, c);
}

void mostrarDivision(int a,int b, float c)
{
    printf("\n\nEl resultado de %d / %d es: %.2f ", a, b, c);
}

void mostrarMultiplicacion(int a,int b, int c)
{
    printf("\n\nEl resultado de %d * %d es: %d ", a, b, c);
}

void mostrarFactorial(int a, int b, int c, int d)
{
    printf("\n\nEl el factorial de %d es: %d y el factorial de %d es: %d \n\n", a, b, c, d);
}
