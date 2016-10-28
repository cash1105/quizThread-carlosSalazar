# README.md

* Para llevar a cabo el quiz usted debe descargar los siguientes archivos
  * `Makefile`
  * `function.c`
  * `function.h`
  * `threaded_multmat.c`
  * `util.c`
  * `util.h`
* Una vez descargdos estos archivos puede comenzar a codificar cada uno de los problemas planteados


Multiplicación de matrices
==========================
Para llevar a cabo la solución de este problema usted debe
* Completar el código que esta en el archivo `threaded_multmat.c`
* Compilar el código usando el comando `make` como sigue `make threaded_multmat`

**Si desea borrar los archivos generados durante la compilación ejecutar el comando `make clean`**

Cómo validar que mi código esta bien?
-------------------------------------
* Edite el archivo `util.h` y cerciorese que la línea `#define TEST` esta **descomentada**
* Compile `make`
* Ejecute la aplicación desde la terminal `./threaded_multmat`

Debería aparecer la palabra `OK` si todo esta bien.

**Cuando este listo para correr la version final, _comente_ la línea que `#define TEST` y compile nuevamente.**

Sumas de Riemann
================
Para este problema usted debe hacer su implementación de la suma de Riemann en un archivo llamado `threaded_riemann.c`. 
Su archivo debe contener,
* Una línea que contenga la invocación al archivo de encabezado `function.h`
```
#include "function.h"
```
* Su implementación de la función que ejecuta el hilo debe invocar a la función `function` definida en el archivo `function.h` y que recibe como parámetro un `double` y devuelve un `double`. 
**Recuerde que esta es la función a la que se le debe calcular el área bajo la curva.**
* Usted debe subir su código en un repositorio de github.

Cómo compilar el código?
------------------------
Para compilar su código ejecute el comando 
```
make threaded_riemann
```
 y ejecute su código 
```
./threaded_riemann
```

Una implementación de las sumas de Riemann
------------------------------------------
En el archivo ``my_riemann.c` pueden encontrar una implementación de las sumas de Riemann. 
Para ver funcionando este código usted debe
```
make my_riemann
```
y ejecuta el código
```
./my_riemann
```
En este código, además de ver una implementación del algoritmo de Riemann, también puede observar la forma como se usa/invoca la función `function`.
