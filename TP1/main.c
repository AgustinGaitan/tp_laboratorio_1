#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "operaciones.h"
#include "informarResultados.h"




int main()
{
    int a = 0;
    int b = 0;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorialA;
    int factorialB;
    int respuesta;
    int flagPrimerOperando = 0;
    int flagSegundoOperando = 0;
    int flagMostrarResultados = 0;

        printf("**Agustin Gaitan 1A**");
    do
    {

        printf("\n********Calculadora********\n\n");
        if(flagPrimerOperando == 0)
        {
            printf("\n1- Ingresar 1er operando (A = x)");

        }
        else
        {
            printf("\n1- Ingresar 1er operando (A = %d)", a);

        }
        if(flagSegundoOperando == 0)
        {
            printf("\n\n2- Ingresar 2do operando (B = y) ");
        }
        else
        {
            printf("\n\n2- Ingresar 2do operando (B = %d)", b);
        }
        printf("\n\n3- Calcular todas las operaciones.");
        printf("\n\n4- Informar resultados.");
        printf("\n\n5- Salir.");
        printf("\n\nIngrese la opcion que desea: ");
        scanf("%d", &respuesta);
        system("cls");

        switch(respuesta)
        {
            case 1:
                printf("\nIngrese el primer operando: ");
                scanf("%d", &a);
                flagPrimerOperando = 1;
                    break;
            case 2:
                printf("\nIngrese el segundo operando: ");
                scanf("%d", &b);
                flagSegundoOperando = 1;
                    break;
            case 3:
                if(flagPrimerOperando && flagSegundoOperando)
                {
                    suma = sumar(a,b);
                    resta = restar(a,b);
                    division = dividir(a,b);
                    multiplicacion = multiplicar(a,b);
                    factorialA = factorial(a);
                    factorialB = factorial(b);
                    flagMostrarResultados = 1;
                    printf("\nLas operaciones han sido realizadas.\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nNo ingreso algun operando.\n");
                    system("pause");

                }
                   break;

            case 4:
                if(flagPrimerOperando && flagPrimerOperando && flagMostrarResultados)
                {


                    printf("\n********Resultados********\n\n");
                    mostarSuma(a, b, suma);
                    mostrarResta(a, b, resta);
                    if( b == 0)
                        {
                           printf("\n\nNo se puede dividir por cero.");
                        }
                        else
                        {
                                mostrarDivision(a, b, division);
                        }
                    mostrarMultiplicacion(a, b, multiplicacion);
                    if(b<0 || a<0)
                    {
                         printf("\n\nNo se puede calcular el factorial de un numero negativo.\nRepita e ingrese uno positivo.\n\n");
                    }
                    else if (a>12)
                    {
                        printf("\n\nError. Ingrese un primer operando menor.\n\n");
                    }
                    else if (b>12)
                    {
                        printf("\n\nError. Ingrese un segundo operando menor.\n\n");
                    }
                    else
                    {
                        mostrarFactorial(a, factorialA, b, factorialB);
                    }
                    system("pause");
                }
                else
                {
                    printf("\nError.No ingreso algun operando o no realizo las operaciones.\n\n");
                    system("pause");
                }
                    break;

        }
        system("cls");





    }while(respuesta!=5);
    return 0;
}
