#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    int rank, size, valor;
    int *recibidos;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    recibidos = (int *)malloc(size * sizeof(int)); // Reserva memoria para los valores recibidos
    valor = rank + 1; // Cada proceso tiene un valor distinto
    printf("Soy el proceso %d y mi valor es: %d \n", rank, valor);
    MPI_Allgather(&valor, 1, MPI_INT, recibidos, 1, MPI_INT, MPI_COMM_WORLD); // Recibe los valores de los procesos

    printf("Soy el proceso %d y los valores recibidos son: ", rank);
    for (int i = 0; i < size; i++){
        printf("%d ", recibidos[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}