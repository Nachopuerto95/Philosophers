<p align="end">
   <strong>🌐 Cambiar idioma:</strong><br>
   <a href="README.es.md">
    <img src="https://github.com/Nachopuerto95/multilang/blob/main/ES.png" alt="Español" width="50">
  </a>&nbsp;&nbsp;&nbsp;
  <a href="/README.md">
    <img src="https://github.com/Nachopuerto95/multilang/blob/main/EN.png" alt="English" width="50">
  </a>
</p>

<h1>🍝 Filósofos (42 cursus)</h1>

<img src="https://github.com/Nachopuerto95/multilang/blob/main/42-Madrid%20-%20Edited.jpg">


## 📜 Acerca del Proyecto

> El proyecto de Filósofos de la Escuela 42 está diseñado en torno al famoso [problema de los filósofos comensales](https://en.wikipedia.org/wiki/Dining_philosophers_problem) de Edsger Dijkstra. \
> Para este proyecto, debemos aprender sobre programación concurrente y sincronización de memoria compartida.

	🚀 Este proyecto es una introducción a lo básico de multihilo y multiproceso.
 	Trabaja en el mismo espacio de memoria, aprende sobre mutexes, semáforos y memoria compartida.

  	🚀 This project is an introduction to the basics of multithreading and multiprocessing.
 	Work on the same memory space, learn about mutexes, semaphores, and shared memory.

> [!NOTE]  
> Debido a los requisitos de la norma de la Escuela 42:
> * Cada función no puede tener más de 25 líneas de código.
> * Todas las variables deben ser declaradas y alineadas en la parte superior de cada función.
> * El proyecto debe ser creado solo con las funciones permitidas.
<br>

### 📋 El problema se describe de la siguiente manera:

* Uno o más filósofos se sientan en una mesa redonda.
* Hay un gran tazón de espaguetis en el centro de la mesa.
* Los espaguetis solo se pueden comer con dos tenedores.
* Solo hay tantos tenedores como filósofos.
* Cada filósofo come, duerme y piensa sucesivamente.
* Si un filósofo no ha comido en un cierto periodo de tiempo, morirá de hambre.
* Los filósofos no pueden comunicarse entre sí.

#### El programa toma los siguientes argumentos:

`./philo <número_de_filosofos> <tiempo_para_morir> <tiempo_para_comer> <tiempo_para_dormir>
[número_de_veces_que_cada_filosofos_debe_comer]`

* **```number_of_philosophers```**: el número de filósofos alrededor de la mesa.
* **```time_to_die```**: un número que representa el tiempo en milisegundos que un filósofo tiene para vivir después de una comida. Si un filósofo no ha comenzado a comer dentro del tiempo `tiempo_para_morir` milisegundos después del inicio de su última comida o el inicio de la simulación, morirá.
* **```time_to_eat```**: un número que representa el tiempo en milisegundos que un filósofo tarda en terminar su comida. Durante ese tiempo, el filósofo mantiene los dos tenedores en las manos.
* **```time_to_sleep```**: el tiempo en milisegundos que un filósofo pasa durmiendo.
* **```number_of_times_each_philosopher_must_eat```**: un argumento opcional que permite que el programa se detenga si todos los filósofos han comido al menos esa cantidad de veces. Si este argumento no se especifica, la simulación continúa a menos que un filósofo muera.

#### El programa registra las acciones de los filósofos en este formato. X es el ID del filósofo:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

### 👨‍💻 Uso

** Compilando el programa**

```shell
$ make
```

** Ejecutar el programa**

Ejecuta el programa con los siguientes argumentos:

shell
Copiar
Editar
./philo <número_de_filosofos> <tiempo_para_morir> <tiempo_para_comer> <tiempo_para_dormir> [número_de_veces_que_cada_filosofos_debe_comer]
Los argumentos deben ser enteros entre 0 e INT_MAX que representan un tiempo en milisegundos. Por ejemplo:

shell
Copiar
Editar
./philo 5 800 200 200 7
Si los argumentos son válidos, el programa mostrará las acciones de cada filósofo hasta que uno de ellos muera o hasta que todos hayan comido número_de_veces_que_cada_filosofos_debe_comer, si se especificó.

<img src="https://github.com/Nachopuerto95/multilang/blob/main/program-example.png"> ```
