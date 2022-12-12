### Ejercicio 1 (1 punto)
* Parte 1: Explicar en qué consiste la comunicación colectiva, las primitivas que hay en MPI y las ventajas y desventajas de este tipo de comunicación.
* Parte 2: Implementar un programa donde el nodo 0 inicializa una variable con la frase “Hola mundo” lo envía al resto de nodos del comunicador.

Cada proceso deberá imprimir por consola: “Soy el proceso X y he recibido el dato Y”

NOTA: Al inicio del programa, el contenido de la variable solo lo conoce el proceso 0.
### Ejercicio 2 (2 puntos)
Implementar un programa donde el nodo 0 inicializa un array unidimensional asignando a cada valor su índice. Este array es dividido en partes, donde cada una de ellas será mandada a un proceso/nodo diferente. Después de que cada nodo haya recibido su porción de datos, los actualiza sumando a cada valor su rank. Por último, cada proceso envía su porción modificada al proceso root.

(Hacerlo para que el número de datos total (N) sea múltiplo del número de procesos).
### Ejercicio 3 (2 puntos)
Implementar un programa donde cada proceso inicializa un array de una dimensión, asignando a todos los elementos el valor de su rank+1. Después el proceso 0 (root) ejecuta dos operaciones de reducción (suma y después producto) sobre los arrays de todos los procesos.
### Ejercicio 4 (5 puntos)
Crear un programa que, haciendo uso de las funciones de comunicación colectiva que se considere necesario, calcule el factorial del número total de procesos. Esto es, si se ejecuta la aplicación con 4 procesos, uno de los procesos tiene que mostrar el resultado 24, si se ejecuta con 5, el resultado sería 120.

Solo un proceso debe conocer el resultado final y deberá imprimir por pantalla: “Soy el proceso X y el factorial de Y es Z”

-----------------------------
Nota: 7,5
