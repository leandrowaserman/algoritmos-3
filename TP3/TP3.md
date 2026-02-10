# TP 3
Aquí tienes los tres ejercicios transcritos en formato Markdown con LaTeX, siguiendo exactamente tu plantilla.

---

## A. Desarrollo

Tomás quiere estudiar cómo fue cambiando el nivel de conectividad de la Ciudad de Buenos Aires a lo largo del tiempo. Para ello, armó un digrafo  donde los  nodos denotan las esquinas de la ciudad, y donde los ejes se corresponden con calles dirigidas que unen estas esquinas. Para estas esquinas conoce el orden cronológico en el que fueron agregadas al trazado de la ciudad.

Para estudiar la conectividad de la ciudad se propone la siguiente tarea: va a ir eliminando las esquinas del grafo en el orden opuesto al que fueron creadas, y cada vez que borra una va a calcular la suma de todas las distancias entre todos los pares de esquinas que todavía están en el mapa. De esta forma, estudiando como aumenta este valor cree poder entender cuáles esquinas fueron las más importantes para aumentar la conectividad de la ciudad entera.

Debemos ayudar a Tomás a completar la tarea que propuso.

### Input

La primera línea contiene un entero  () indicando el número de esquinas de la ciudad.

Las siguientes  líneas contienen  enteros cada una. El -esimo entero en la línea  indica la longitud de la calle que une a  con . Esta longitud es a lo sumo . La última línea tiene  números distintos, e indican el orden cronológico invertido en el cual fueron agregadas las esquinas. Es decir, la primera esquina de esta lista es la última que fue creada, y por lo tanto la primera que va a quitar Tomás.

### Output

Se deben imprimir  enteros. El -esimo de estos debe indicar la suma de las distancias de los nodos que quedan tras eliminar del grafo las últimas  esquinas que fueron creadas.

### Example

**Input:**

```text
1
0
1
4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3

```

**Output:**

```text
0
17 23 404 0

```

*(Nota: He combinado los ejemplos en uno solo siguiendo la lógica usual, pero si prefieres los 3 bloques separados como en la imagen, avísame).*

---

## B. Aulas sobrecargadas

Los docentes de Intro se organizaron para tomar el parcial en  aulas distintas, pero debido a una confusión en la distribución de los alumnos ahora las aulas están sobrecargadas. Puntualmente, en el aula  se sentaron  estudiantes, cuando en realidad la misma está pensada únicamente para una cantidad .

Se quiere descubrir si es posible reorganizar a los alumnos para que cada aula tenga exactamente  estudiantes, teniendo en cuenta que no es posible mover alumnos entre ciertas aulas. Puntualmente, se conocen los pares de aulas  tales que es posible mover a los alumnos del aula  al aula . Como el parcial está por empezar, cada alumno puede hacer a **lo sumo un movimiento**. Es decir, un alumno no puede ir del aula  a la  y luego a la .

### Input

La primera línea de la entrada tiene dos enteros  y  () indicando la cantidad de aulas y la cantidad de pares de aulas tales que es posible mover alumnos entre ellas.

La siguiente línea tiene los  valores  ().

La siguiente, los  valores  ().

Finalmente hay  líneas conteniendo cada una dos enteros  y  () indicando que es válido mover alumnos tanto del aula  hacia la  como de la  hacia la .

### Output

Si es imposible reorganizar a los alumnos se debe devolver `NO`.

Caso contrario, se debe devolver `YES` junto a  líneas adicionales, cada una con  enteros. El -ésimo número en la -ésima fila debe indicar cuántos estudiantes del aula  deben moverse al aula  (el -ésimo número de la -ésima fila debe indicar cuántos tienen que quedarse en esa aula).

Si hay varias respuestas posibles, cualquiera es válida.

### Example

**Input:**

```text
4 4
1 2 6 3
3 5 3 1
1 2
2 3
3 4
4 2
2 0
1 2
2 1

```

**Output:**

```text
YES
1 0 0 0
2 0 0 0
0 5 1 0
0 0 2 1
NO

```

---

## C. Seguridad

Tuki está ayudando al Gobierno de la Ciudad a instalar sistemas de seguridad en las distintas calles de la Capital. Esta se modela como un multigrafo no dirigido con  nodos donde estos denotan esquinas de la ciudad mientras que los ejes representan las calles. Para cada calle se conoce su longitud y el costo de colocar un sistema de seguridad en la misma, el cual es exactamente el doble de su longitud.

Como cubrir todas las calles es muy caro, el Gobierno se propone solo cubrir aquellas que pertenecen a algún camino mínimo entre el nodo  y el , y está interesado en descubrir el costo del proyecto.

Debemos ayudar a Tuki a resolver este problema. Para eso, debemos diseñar un algoritmo que dada la descripción de la ciudad encuentre el costo de instalar sistemas de seguridad en todas las calles que pertenecen a algún camino mínimo entre el nodo  y el .

### Input

La entrada consiste de una primera línea con dos enteros  () que denotan respectivamente la cantidad de esquinas y la cantidad de calles, seguida de  líneas con 3 enteros  y  indicando que hay una calle bidireccional entre los nodos  y  de largo  (con ). Puede haber más de una calle entre dos esquinas, e incluso calles que conecten una esquina consigo misma (a lo Parque Chas). Se sabe que existe por lo menos una forma de llegar de la esquina  a la esquina .

### Output

Se debe imprimir un único número indicando el costo de instalar un sistema de seguridad en cada calle que pertenece a algún camino mínimo entre las esquinas  y .

### Example

**Input:**

```text
4 7
0 1 1
0 2 2
0 3 10
0 3 3
1 3 2
2 3 1
1 1 1
3 3
0 1 2
1 2 4
2 0 5

```

**Output:**

```text
18
10

```Aquí tienes los tres ejercicios transcritos en formato Markdown con LaTeX, siguiendo exactamente tu plantilla.

---

## A. Desarrollo

Tomás quiere estudiar cómo fue cambiando el nivel de conectividad de la Ciudad de Buenos Aires a lo largo del tiempo. Para ello, armó un digrafo  donde los  nodos denotan las esquinas de la ciudad, y donde los ejes se corresponden con calles dirigidas que unen estas esquinas. Para estas esquinas conoce el orden cronológico en el que fueron agregadas al trazado de la ciudad.

Para estudiar la conectividad de la ciudad se propone la siguiente tarea: va a ir eliminando las esquinas del grafo en el orden opuesto al que fueron creadas, y cada vez que borra una va a calcular la suma de todas las distancias entre todos los pares de esquinas que todavía están en el mapa. De esta forma, estudiando como aumenta este valor cree poder entender cuáles esquinas fueron las más importantes para aumentar la conectividad de la ciudad entera.

Debemos ayudar a Tomás a completar la tarea que propuso.

### Input

La primera línea contiene un entero  () indicando el número de esquinas de la ciudad.

Las siguientes  líneas contienen  enteros cada una. El -esimo entero en la línea  indica la longitud de la calle que une a  con . Esta longitud es a lo sumo . La última línea tiene  números distintos, e indican el orden cronológico invertido en el cual fueron agregadas las esquinas. Es decir, la primera esquina de esta lista es la última que fue creada, y por lo tanto la primera que va a quitar Tomás.

### Output

Se deben imprimir  enteros. El -esimo de estos debe indicar la suma de las distancias de los nodos que quedan tras eliminar del grafo las últimas  esquinas que fueron creadas.

### Example

**Input:**

```text
1
0
1
```
```text
4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3
```

**Output:**

```text
0
```
```text
17 23 404 0

```

[Ver Solución](./problemA.cpp)

---

## B. Aulas sobrecargadas

Los docentes de Intro se organizaron para tomar el parcial en  aulas distintas, pero debido a una confusión en la distribución de los alumnos ahora las aulas están sobrecargadas. Puntualmente, en el aula  se sentaron  estudiantes, cuando en realidad la misma está pensada únicamente para una cantidad .

Se quiere descubrir si es posible reorganizar a los alumnos para que cada aula tenga exactamente  estudiantes, teniendo en cuenta que no es posible mover alumnos entre ciertas aulas. Puntualmente, se conocen los pares de aulas  tales que es posible mover a los alumnos del aula  al aula . Como el parcial está por empezar, cada alumno puede hacer a **lo sumo un movimiento**. Es decir, un alumno no puede ir del aula  a la  y luego a la .

### Input

La primera línea de la entrada tiene dos enteros  y  () indicando la cantidad de aulas y la cantidad de pares de aulas tales que es posible mover alumnos entre ellas.

La siguiente línea tiene los  valores  ().

La siguiente, los  valores  ().

Finalmente hay  líneas conteniendo cada una dos enteros  y  () indicando que es válido mover alumnos tanto del aula  hacia la  como de la  hacia la .

### Output

Si es imposible reorganizar a los alumnos se debe devolver `NO`.

Caso contrario, se debe devolver `YES` junto a  líneas adicionales, cada una con  enteros. El -ésimo número en la -ésima fila debe indicar cuántos estudiantes del aula  deben moverse al aula  (el -ésimo número de la -ésima fila debe indicar cuántos tienen que quedarse en esa aula).

Si hay varias respuestas posibles, cualquiera es válida.

### Example

**Input:**

```text
4 4
1 2 6 3
3 5 3 1
1 2
2 3
3 4
4 2
```
```text
2 0
1 2
2 1
```

**Output:**

```text
YES
1 0 0 0
2 0 0 0
0 5 1 0
0 0 2 1
```
```text
NO
```

[Ver Solución](./problemB.cpp)

---

## C. Seguridad

Tuki está ayudando al Gobierno de la Ciudad a instalar sistemas de seguridad en las distintas calles de la Capital. Esta se modela como un multigrafo no dirigido con  nodos donde estos denotan esquinas de la ciudad mientras que los ejes representan las calles. Para cada calle se conoce su longitud y el costo de colocar un sistema de seguridad en la misma, el cual es exactamente el doble de su longitud.

Como cubrir todas las calles es muy caro, el Gobierno se propone solo cubrir aquellas que pertenecen a algún camino mínimo entre el nodo  y el , y está interesado en descubrir el costo del proyecto.

Debemos ayudar a Tuki a resolver este problema. Para eso, debemos diseñar un algoritmo que dada la descripción de la ciudad encuentre el costo de instalar sistemas de seguridad en todas las calles que pertenecen a algún camino mínimo entre el nodo  y el .

### Input

La entrada consiste de una primera línea con dos enteros  () que denotan respectivamente la cantidad de esquinas y la cantidad de calles, seguida de  líneas con 3 enteros  y  indicando que hay una calle bidireccional entre los nodos  y  de largo  (con ). Puede haber más de una calle entre dos esquinas, e incluso calles que conecten una esquina consigo misma (a lo Parque Chas). Se sabe que existe por lo menos una forma de llegar de la esquina  a la esquina .

### Output

Se debe imprimir un único número indicando el costo de instalar un sistema de seguridad en cada calle que pertenece a algún camino mínimo entre las esquinas  y .

### Example

**Input:**

```text
4 7
0 1 1
0 2 2
0 3 10
0 3 3
1 3 2
2 3 1
1 1 1
```
```text
3 3
0 1 2
1 2 4
2 0 5
```

**Output:**

```text
18
```
```text
10
```

[Ver Solución](./problemC.cpp)