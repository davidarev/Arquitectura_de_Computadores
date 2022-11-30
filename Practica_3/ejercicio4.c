#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size; // Variables para el rango y el tamaño del comunicador
    int fact = 1;
    int fact_total = 1;

    MPI_Init(&argc, &argv); // Inicialización del comunicador
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtención del rango del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtención del tamaño del comunicador

    for (int i = 1; i <= size; i++){
        fact *= i;
    }
    MPI_Reduce(&fact, &fact_total, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    if (rank == 0){ // Si el proceso es el 0
        printf("Soy el proceso %d y el factorial de '%d' es '%d' \n", rank, size, fact);
    }

    MPI_Finalize(); // Finalización del comunicador
    return 0;
}
