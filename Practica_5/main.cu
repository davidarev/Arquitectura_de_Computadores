/*
 * ¡¡¡ACLARACIÓN A TENER EN CUENTA!!!
 * El código NO ha sido probado en un equipo con una tarjeta gráfica NVIDIA,
 * por lo que no se puede asegurar su correcto funcionamiento.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define N 10000000

__global__ void kernel_suma(float *arr1, float *arr2, int dim){ // Función kernel que suma dos vectores de dimensión dim y guarda el resultado en arr1
    int id = threadIdx.x + (blockIdx.x * blockDim.x); // id es igual al número de hilo que se está ejecutando en el momento de la llamada a la función
    if (id < dim) arr1[id] = arr1[id] + arr2[id];
}

int main(){
    float *arr1 = (float *)malloc(N * sizeof(float)); // Reserva de memoria para el array arr1
    float *arr2 = (float *)malloc(N * sizeof(float)); // Reserva de memoria para el array arr2
    float *out = (float *)malloc(N * sizeof(float)); // Reserva de memoria para el array resolver
    float *p_arr1, *p_arr2, *p_out; // Declaración de punteros para los arrays arr1, arr2 y resolver en el dispositivo

    cudaMalloc((void **)&p_arr1, sizeof(float) * N); // Reserva de memoria en el dispositivo para el array arr1
    cudaMalloc((void **)&p_arr2, sizeof(float) * N); // Reserva de memoria en el dispositivo para el array arr2
    cudaMalloc((void **)&p_out, sizeof(float) * N); // Reserva de memoria en el dispositivo para el array resolver

    memset(arr1, 0, sizeof(float) * N); // Inicialización del array arr1.
    memset(arr2, 0, sizeof(float) * N); // Inicialización del array arr2
    for (int i = 0; i < N; i++){
        arr1[i] = 1.0f; // Asignación de valores al array arr1
        arr2[i] = 2.0f; // Asignación de valores al array arr2
    }

    printf("Array A: ");
    for (int i = 0; i < N; i++){
        printf("%d,", arr1[i]); // Impresión del array arr1
    }

    printf("\nArray B: ");
    for (int i = 0; i < N; i++){
        printf("%d,", arr2[i]); // Impresión del array arr2
    }

    cudaMemcpy(p_arr1, arr1, sizeof(float) * N, cudaMemcpyHostToDevice); // Copia de los datos del array arr1 al array p_arr1 en el dispositivo
    cudaMemcpy(p_arr2, arr2, sizeof(float) * N, cudaMemcpyHostToDevice); // Copia de los datos del array arr2 al array p_arr2 en el dispositivo
    dim3 nthreads(256); // Variable de tipo dim3 que contiene el número de hilos por bloque, en este caso 256
    dim3 nblocks((N / nthreads.x) + (N % nthreads.x ? 1 : 0)); // Variable de tipo dim3 que contiene el número de bloques, en este caso N/256 + 1
    kernel_suma <<< nblocks.x, nthreads.x >>> (arr1, arr2, N); // Llamada a la función kernel_suma
    cudaDeviceSynchronize(); // Espera a que todos los hilos terminen su ejecución
    cudaMemcpy(resolver, arr1, sizeof(float) * N, cudaMemcpyDeviceToHost); // Copia el resultado de la suma de los arrays arr1 y arr2 al array resolver

    printf("\nResolver: ");
    for (int i = 0; i < N; i++){
        printf("%d,", out[i]); // Impresión del array resolver
    }

    // Liberación de memoria
    free(arr1);
    free(arr2);
    free(out);
    cudaFree(p_arr1);
    cudaFree(p_arr2);
    cudaFree(p_out);

    return 0;
}
