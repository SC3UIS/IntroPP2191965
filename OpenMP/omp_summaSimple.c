/*
 * Tomado de: https://github.com/carlosjaimebh/SomeExamples/blob/main/summaSimple.c
 * Modificado por ThesplumCoder para hacer la práctica de paralelizar el algoritmo.
 * Es un programa que realiza la sumatoria de los primeros 10000 números naturales.
 * */

#include <omp.h>
#include <stdio.h>

int main()
{
    /**
     * Con respecto al bloque original lo que hice fue definir la cantidad de los
     * números naturales que iba a sumar, la dejé fija. Esto lo hice así porque para
     * poder correr el algoritmo en GUANE, cuando lo mandaba a correr en algún nodo, 
     * se quedaba a la espera de que ingresara el argumento y se paraba, entonces lo 
     * dejé fijo para solucionar esto.
     */
    int num=10000, count, sum = 0;
    printf("Enter a positive integer: 10000\n");

    #pragma omp parallel
    {
        #pragma omp for reduction(+:sum)
        for(count = 1; count <= num; ++count)
        {
            sum += count;
        }
    }

    printf("\nSum = %d\n", sum);

    return 0;
}
