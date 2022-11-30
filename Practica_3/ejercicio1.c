#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size; // Variables para el rango y el tamaño del comunicador
    char msg[100];

    MPI_Init(&argc, &argv); // Inicialización del comunicador
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtención del rango del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtención del tamaño del comunicador

    if (rank == 0) { // Si el proceso es el 0
        sprintf(msg, "Hola mundo");
        for (int i = 1; i < size; i++) {
        printf("Soy el proceso master y he enviado el dato %s al proceso\n", msg, i); 
           MPI_Send(msg, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD); // Envío del mensaje
        }
    } else { // Si el proceso no es el 0
        MPI_Recv(msg, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Recibe el mensaje del proceso 0
        printf("Soy el proceso %d y he recibido el dato %s del proceso master\n", rank, msg);
    }

    MPI_Finalize(); // Finalización del comunicador
    return 0;
}
