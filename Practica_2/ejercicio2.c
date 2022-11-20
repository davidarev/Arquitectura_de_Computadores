#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    int rank, nProcesos, dato; 

    MPI_Status status; 

    MPI_Init(&argc, &argv); // Inicializa el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtiene el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &nProcesos); // Obtiene el número de procesos

    srand(time(NULL));
    dato = rand() % 100; // Genera un número aleatorio entre 0 y 99

    if(rank == 0){ // Si es el proceso 0
        for(int i = 1; i < nProcesos; i++) { // Recibe los mensajes de los demás procesos
            MPI_Recv(&dato, 1, MPI_INT, i, i, MPI_COMM_WORLD, &status); // Recibe el mensaje
            printf("Soy el proceso 0 y he recibido el valor %i del proceso %i \n", dato, i); // Imprime el mensaje
        }
        printf("Soy el proceso 0 y ya he recibido los datos de los %i procesos: ", nProcesos); 
        for(int i = 1; i < nProcesos; i++) { 
            MPI_Recv(&dato, 1, MPI_INT, i, i, MPI_COMM_WORLD, &status); 
            printf("%i ", dato); 
        }
    }
    else{
        MPI_Send(&dato, 1, MPI_INT, 0, rank, MPI_COMM_WORLD); // Envía el mensaje al proceso 0
        printf("Soy el proceso %i y he inicializado la variable con el dato %i \n", rank, dato); // Imprime el mensaje
    }

    MPI_Finalize(); // Finaliza el entorno MPI
    return 0; // Finaliza el programa
}