### Ejercicio 1 (1 punto)
Crear un ejemplo sencillo de uso de cada primitiva explicada en esta práctica (MPI_Reduce, MPI_Allgather y MPI_Alltoall) y utilizarlo para explicar el funcionamiento de cada una de ellas. Estos ejemplos deben funcionar correctamente con cualquier número de procesos.

### Ejercicio 2 (3 puntos)
Implementar un programa que realice la transposición de una matriz.
Realizar el proceso en paralelo, distribuyendo la matriz entre 4 procesos.

### Ejercicio 3 (6 puntos)
Conversión a decimal un número binario.
Haciendo uso de las funciones explicadas en este guion, implementar un programa donde los procesos calculan en paralelo la representación decimal de un número binario:
• El número de procesos con el que se lance la aplicación será igual que el número de bits del número binario.
• Al iniciar la aplicación cada proceso genera un valor aleatorio (0 o 1) y se lo envía al resto. Uno de los procesos deberá imprimir por pantalla el número que se va a pasar a decimal.
• Una vez que todos los procesos tienen el dato, hacen las operaciones necesarias para calcular el valor decimal de forma paralela.
• Solo un proceso conoce el resultado final en decimal y lo imprime por pantalla.
