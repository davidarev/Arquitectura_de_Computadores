#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    int rank, size, valor, suma;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    valor = rank + 1; // Cada proceso tiene un valor distinto
    printf("Soy el proceso %d y mi valor es: %d \n", rank, valor);
    MPI_Reduce(&valor, &suma, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); // Suma los valores de los procesos

    if (rank == 0){
        printf("Soy el proceso master y la suma es: %d\n", suma); // Imprime la suma
    }

    MPI_Finalize();
    return 0;
}
