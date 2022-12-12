### Ejercicio 1 (1 punto)
Explicar en qué consiste la comunicación punto a punto, los tipos de primitivas que hay en MPI y las ventajas y desventajas de este tipo de comunicación.

### Ejercicio 2 (4 puntos)
Implementar un código donde cada proceso del comunicador inicializa una variable con un valor aleatorio (distinto para cada proceso) y se la envía al proceso 0 utilizando las primitivas bloqueantes de comunicación punto a punto. Una vez recibidas todas, el proceso 0 imprime por pantalla los valores ordenados por número de proceso.

Ejemplo de la salida por consola con 4 procesos:
* Cada proceso imprime: “Soy el proceso X y he inicializado la variable con el dato X”.
* El proceso 0 imprime tantas veces como procesos haya: “Soy el proceso 0 y he recibido el valor X del proceso X”
* Por último, el proceso 0 imprime una vez: “Soy el proceso 0 y ya he recibido los datos de los X procesos: datoProceso0 datoProceso1 datoProceso2 datoProceso3 ”

### Ejercicio 3 (4 puntos)
Implementar un código donde utilizando comunicación punto a punto tres procesos rebotan continuamente los mensajes entre sí, hasta que deciden detenerse una vez alcanzado límite autoimpuesto.

-----------------------------
Nota: 9
