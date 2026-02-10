# TP 2

## A. ¿Qué aristas van en un AGM?
Un día Echu y Tuki estaban aburridos y se pusieron a conversar sobre árboles generadores mínimos (AGMs). Tuki le recordaba a Echu que dado un grafo conexo siempre existe un árbol generador mínimo, pero que no es necesariamente único, pueden existir varios.

Echu al escuchar esas palabras se puso a reflexionar y se preguntó si para cada arista de un grafo conexo, se podía ver si la arista pertenecía a todos los árboles generadores mínimos que existen, a al menos un árbol generador mínimo, o a ninguno.

Tuki se quedó pensando y le respondió que si tiene un grafo con todas aristas de distinto peso, entonces existe un sólo árbol generador mínimo. Pueden existir varios árboles generadores mínimos solamente si existen múltiples aristas con pesos iguales, ya que en algunos casos una arista se puede reemplazar por otra del mismo peso en un AGM.

Echu pensó rápidamente que cuando se topaba con un grupo de aristas del mismo peso quizás se podía construir un nuevo grafo G′ cuando se estuviese construyendo el AGM, donde cada vértice sea una componente conexa del bosque original construido por el AGM y las aristas que se quieren analizar (las que son del mismo peso) son agregadas para conectar las componentes. Pensó que eso podría ser útil para determinar la clasificación de las aristas. Ver si hay aristas que son puentes o se genera algún ciclo puede ayudar.

Después de discutir un rato, a Tuki le pareció genial el problema que planteó Echu y decidió sugerirle a Eric que agregue ese problema al TP2 de la materia. Tu tarea ahora es resolver el problema planteado por Echu.

### Input
La primera línea contiene dos enteros $n$ y $m$ ($2 \le n \le 10^5$, $n - 1 \le m \le min(10^5, \frac{n(n-1)}{2})$) — El número de vértices y aristas del grafo, respectivamente. Luego, siguen $m$ líneas, cada una con 3 enteros — se describe a las aristas del grafo como "$a_i \ b_i \ w_i$" ($1 \le a_i, b_i \le n, 1 \le w_i \le 10^6, a_i \neq b_i$), donde $a_i$ y $b_i$ son los números de vértices conectados por la $i$-ésima arista, y $w_i$ es el peso de la $i$-ésima arista. Está garantizado que el grafo es conexo y que no contiene loops ni múltiples aristas.

### Output
Imprimir $m$ líneas — la respuesta para todas las aristas. Si la $i$-ésima arista está incluida en todos los AGM, imprimir `any`. Si la $i$-ésima arista está incluida en al menos un AGM, imprimir `at least one`. Si la $i$-ésima arista no está incluida en ningún AGM, imprimir `none`. Imprimir las respuestas para las aristas en el orden en el cual las aristas fueron especificadas en el input.

### Example

**Input:**
```text
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
```
**Output:**
```text
none
any
at least one
at least one
any
```
**Input:**
```text
3 3
1 2 1
2 3 1
1 3 2
```
**Output:**
```text
any
any
none
```
**Input:**
```text
3 3
1 2 1
2 3 1
1 3 1
```
**Output:**
```text
at least one
at least one
at least one
```

--- 
[Ver Solución](./problemA.cpp)

## B. Igna, Martín y la bipartitud

Igna y Martín continúan sus aventuras! Como todos en TDA saben, a los JTPs les gustan los grafos bipartitos, especialmente los árboles.

Un grafo bipartito es un grafo cuyos vértices se pueden dividir en  conjuntos de tal manera que para cada arista  que pertenece al grafo,  y  pertenecen a diferentes conjuntos. Podés encontrar una definición más formal de un grafo bipartito en la sección de notas a continuación.

Los JTPs le dieron a Igna y Martín un árbol que consiste en  nodos y les pidieron que agregaran aristas al mismo de tal manera que el grafo siga siendo bipartito. Además, después de agregar estas aristas, el grafo debe ser simple (no debe contener loops, ni aristas múltiples). ¿Cuál es el número máximo de aristas que pueden agregar?

Un loop es una arista que conecta un nodo consigo mismo. Un grafo no contiene aristas múltiples cuando para cada par de nodos no hay más de una arista entre ellos. Un ciclo y un loop **no son lo mismo**.

### Input

La primera línea de entrada contiene un entero  — el número de nodos en el árbol ().

Las siguientes  líneas contienen enteros  y  () — la descripción de las aristas del árbol.

Se garantiza que el grafo dado es un árbol.

### Output

Imprimir un número entero — el número máximo de aristas que Igna y Martín pueden agregar al árbol mientras cumplan con las condiciones.

### Example

**Input:**

```text
3
1 2
1 3
5
1 2
2 3
3 4
4 5

```

**Output:**

```text
0
2

```

[Ver Solución](./problemB.cpp)

---

## C. Juli y los túneles de Exactas

En estos últimos años, Juli estuvo muy ocupado estudiando para exámenes y el concurso de Ay1. Ahora que ya se recibió quiere relajarse y recorrer todo Exactas tranquilo.

Exactas consta de  aulas numeradas del  al . Juli comienza a caminar desde el aula número  (en particular, el aula 6 del Pabe II) y sigue alguna secuencia de aulas. Caminar desde el espacio número  hasta otro espacio  requiere  unidades de energía. La *energía total* gastada por Juli al visitar una secuencia de aulas  es igual a  unidades de energía.

Por supuesto, caminar sería aburrido si no hubiera atajos. Un *atajo* es un túnel oculto que permite a Juli caminar de un aula a otra requiriendo solo  unidad de energía. Hay exactamente  atajos en Exactas; el -ésimo de ellos permite caminar desde el aula  hasta el aula  () (pero no en la dirección opuesta), por lo tanto, hay exactamente un atajo que comienza en cada aula.

Formalmente, si Juli elige una secuencia , entonces para cada  que satisface  y , Juli gastará **solo 1 unidad de energía** en lugar de  al caminar desde el aula  hasta el aula . Por ejemplo, si Juli elige una secuencia , gastará exactamente  unidades de energía total al recorrerlas.

Antes de emprender su aventura, Juli te pide que encuentres la cantidad mínima de energía requerida para alcanzar cada una de las intersecciones desde el aula inicial. Formalmente, para cada , Juli está interesado en encontrar la mínima energía total posible de alguna secuencia .

### Input

La primera línea contiene un entero  () — el número de aulas en Exactas (cambian cada cuatri).

La segunda línea contiene  enteros  (), describiendo los atajos de Exactas, que permiten caminar desde el aula  hasta el aula  usando solo  unidad de energía. Tené en cuenta que los atajos no permiten caminar en dirección opuesta (de  a ).

### Output

En la única línea, imprimí  enteros , donde  denota la menor cantidad de energía total requerida para caminar desde el aula  hasta el aula .

### Example

**Input:**

```text
3
2 2 3
```
```text
5
1 2 3 4 5
```
```text
7
4 4 4 4 7 7 7
```

**Output:**

```text
0 1 2
```
```text
0 1 2 3 4
```
```text
0 1 2 1 2 3 3
```
### Note

En el primer caso de muestra, las secuencias deseadas son:

$1: (1); m_1 = 0;$
$2: (1, 2); m_2 = 1;$
$3: (1, 3); m_3 = |3 - 1| = 2.$

En el segundo caso de muestra, la secuencia para cualquier aula $1 < i$ es siempre $(1, i)$ y $m_i = |1 - i|$.

En el tercer caso de muestra, unas secuencias posibles son:

$1: (1); m_1 = 0;$
$2: (1, 2); m_2 = |2 - 1| = 1;$
$3: (1, 4, 3); m_3 = 1 + |4 - 3| = 2;$
$4: (1, 4); m_4 = 1;$
$5: (1, 4, 5); m_5 = 1 + |4 - 5| = 2;$
$6: (1, 4, 6); m_6 = 1 + |4 - 6| = 3;$
$7: (1, 4, 5, 7); m_7 = 1 + |4 - 5| + 1 = 3$

---
[Ver Solución](./problemC.cpp)