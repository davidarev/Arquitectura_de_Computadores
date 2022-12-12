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

    valor = rank + 1; // Cada proceso tiene un valor distinto
    //Los procesos imprimen sus valores
    printf("Soy el proceso %d y mi valor es: %d \n", rank, valor);
    recibidos = (int *)malloc(size * sizeof(int)); // Reserva memoria para los valores recibidos
    MPI_Alltoall(&valor, 1, MPI_INT, recibidos, 1, MPI_INT, MPI_COMM_WORLD); // Envía y recibe los valores

    printf("Soy el proceso %d y recibí los valores: ", rank);
    for (int i = 0; i < size; i++){
        printf("%d ", recibidos[i]);
    }
    printf("\n");

    free(recibidos); // Libera la memoria
    MPI_Finalize();
    return 0;
}
