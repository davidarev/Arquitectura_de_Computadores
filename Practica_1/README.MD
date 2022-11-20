### Ejercicio 1 (2 Puntos)
Implementar un programa usando MPI, que imprima por salida estándar: “Hola mundo, soy el proceso X de un total de Y.”
cuando el número total de tareas es Y y X un rango de 0 a Y-1.

### Ejercicio 2 (4 Puntos)
Implementar un programa usando MPI, donde el proceso 0 toma un dato del usuario y lo envía al siguiente nodo, que lo envía al siguiente y así hasta llegar al último nodo. Esto es, el proceso i recibe de i-1 y transmite el dato a i+1, hasta que el dato alcanza el último nodo.

### Ejercicio 3 (4 Puntos)
Modificar la implementación del ejercicio 2 para que el dato introducido por el usuario dé tantas vueltas como este indique en anillo
