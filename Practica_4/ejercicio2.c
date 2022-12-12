#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4 // Tamaño de la matriz
#define P 4 //Numero de procesos

int main(int argc, char *argv[]) {
    int rank, size;
    int matriz[N][N] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    }; // Inicializamos la matriz
    int matriz_transpuesta[N][N]; // Declaramos la matriz transpuesta
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != P) { // Comprobamos que el número de procesos sea 4
        printf("El programa debe ejecutarse con %d procesos.\n", P);
        MPI_Finalize();
        exit(0); // Salimos del programa
    }

    if(rank == 0){
        printf("La matriz original es: \n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    MPI_Scatter(matriz, N*N, MPI_INT, matriz_transpuesta, N*N, MPI_INT, 0, MPI_COMM_WORLD); // Enviamos la matriz a los procesos

    for (int i = 0; i < N; i++) { // Transponemos la matriz
        for (int j = 0; j < N; j++) {
            matriz_transpuesta[i][j] = matriz[j][i];
        }
    }

    MPI_Gather(matriz_transpuesta, N*N, MPI_INT, matriz, N*N, MPI_INT, 0, MPI_COMM_WORLD); // Recogemos la matriz transpuesta

    if (rank == 0) { //El proceso master imprime la matriz transpuesta
        printf("La matriz transpuesta es: \n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}