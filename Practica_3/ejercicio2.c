#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 10

int main(int argc, char *argv[]) {
    int rank, size, i;
    int *array, *subarray;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        array = (int *) malloc(N * sizeof(int));
        for (i = 0; i < N; i++) {
            array[i] = i;
        }
        for (i = 0; i < size; i++) {
            printf("El proceso 0 envia %d al proceso %d \n", array[i], i);
        }
    }

    subarray = (int *) malloc(N / size * sizeof(int)); //Reserva de memoria para el subarray
    MPI_Scatter(array, N / size, MPI_INT, subarray, N / size, MPI_INT, 0, MPI_COMM_WORLD); //Envio de datos a los procesos hijos desde el proceso 0
    for (i = 0; i < N / size; i++) {
        subarray[i] += rank;
    }
    MPI_Gather(subarray, N / size, MPI_INT, array, N / size, MPI_INT, 0, MPI_COMM_WORLD); //Recogida de datos de los procesos hijos en el proceso 0

    if (rank == 0) {
        printf("El proceso 0 recibe: ");
        for (i = 0; i < N; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
