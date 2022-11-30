#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 10 // Tamaño del array

int main(int argc, char *argv[]) {
    int rank, size; // Variables para el rango y el tamaño del comunicador
    int *array, *array_suma, *array_producto;
    MPI_Status status;

    MPI_Init(&argc, &argv); // Inicialización del comunicador
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtención del rango del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtención del tamaño del comunicador

    array = (int *) malloc(N * sizeof(int)); // Reserva de memoria para el array
    array_suma = (int *) malloc(N * sizeof(int));
    array_producto = (int *) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        array[i] = rank + 1; // Rellenamos el array
    }

    MPI_Reduce(array, array_suma, N, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); // Suma de los arrays
    MPI_Reduce(array, array_producto, N, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD); // Producto de los arrays

    if (rank == 0) { // Si el proceso es el 0
        printf("Array suma: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", array_suma[i]); // Imprime el array
        }
        printf(" Array producto: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", array_producto[i]); // Imprime el array
        }
        printf("\n");
    }

    MPI_Finalize(); // Finalización del comunicador
    return 0;
}
