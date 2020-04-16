#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

/** \brief   Se le pide al usuario ingresar dos operandos
 *
 * \param    Se ingresa el 1er operando
 * \param    Se ingresa el 2do operando
 * \return   La operacion realizada
 *
 */


int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}

float dividir(int a, int b)
{
    float resultado;

    resultado = (float) a / b;


    return resultado;

}

int multiplicar(int a, int b)
{
    return a * b;
}

int factorial(int a)
{

    int fact = 0;

    if ( a >= 0)
    {
        if (a == 1 || a == 0)
        {
            fact = 1;
        }
        else
        {
            fact = a * factorial(a - 1);
        }

    }
    return fact;
}

