#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]){
    int rank, size, bit; // Variables para el rango, el tamaño del proceso, y el valor a generado

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *binario = (int *)malloc(size * sizeof(int)); // Se crea un arry para guardar los valores generados
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        bit = rand() % 2; // Se genera un valor aleatorio entre 0 y 1
        MPI_Allgather(&bit, 1, MPI_INT, binario, 1, MPI_INT, MPI_COMM_WORLD); // Se envia el valor generado a todos los procesos y se guarda en el array
    }

    int decimal = 0;
    for(int i = 0; i < size; i++){
        decimal += binario[i] * pow(2, i); // Se calcula el valor decimal
    }

    if(rank == 0){
        for(int i = 0; i < size; i++){
            printf("Soy el proceso %d y el valor generado es %d \n", i, binario[i]); // Se imprime el valor generado por cada proceso
        }
        printf("El numero binario es: ");
        for(int i = size - 1; i >= 0; i--){
            printf("%d", binario[i]); // Se imprime el numero binario
        }
        printf("\n");
        printf("Valor decimal: %d\n", decimal); // Se imprime el valor decimal
    }

    MPI_Finalize();
    return 0;
}


