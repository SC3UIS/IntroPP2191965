#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"

int main (int argc, char *argv[]) {
    int num, count, sum = 0;

    num = (int) strtol(argv[1], NULL, 10);

    int tareas, rango;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &tareas);
    MPI_Comm_rank(MPI_COMM_WORLD, &rango);
    int tamanho_trozo = num / tareas;
    int inicio_trozo = rango * tamanho_trozo + 1;
    int fin_trozo = inicio_trozo + tamanho_trozo - 1;

    int suma_parcial = 0;
    for(count = inicio_trozo; count <= fin_trozo; count++) {
        suma_parcial += count;
    }

    MPI_Reduce(&suma_parcial, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rango == 0) {
        printf("Enter a positive integer: %d\n", num);
        printf("\nSum = %d\n", sum);
    }
    MPI_Finalize();
    return 0;
}
