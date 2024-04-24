# code-generation-optimization
This is a study of the code generation and optimization, and being more precise about the loop unrolling


Cache L1
Tamaño de la caché L1 de instrucciones (L1i):
Nivel de rendimiento 0: 196,608 bytes (192 KB)
Nivel de rendimiento 1: 131,072 bytes (128 KB)
Tamaño de la caché L1 de datos (L1d):
Nivel de rendimiento 0: 131,072 bytes (128 KB)
Nivel de rendimiento 1: 65,536 bytes (64 KB)
Cache L2
Tamaño de la caché L2:
Nivel de rendimiento 0: 16,777,216 bytes (16 MB)
Nivel de rendimiento 1: 4,194,304 bytes (4 MB)
La información también indica los tamaños de caché general para varios niveles de rendimiento. El hw.l1icachesize, hw.l1dcachesize y hw.l2cachesize muestran tamaños para un nivel básico (probablemente el más común o predeterminado):

Cache L1 de instrucciones: 131,072 bytes (128 KB)
Cache L1 de datos: 65,536 bytes (64 KB)
Cache L2: 4,194,304 bytes (4 MB)


1. Gráfico de Tiempos de Ejecución
Eje X: Número de iteraciones del bucle.
Eje Y: Tiempo de ejecución en segundos.
Descripción: Puedes variar el número de iteraciones o el tamaño del arreglo mientras mides los tiempos de ejecución del bucle normal y del bucle desenrollado. Esto te permitirá visualizar cómo afecta el desenrollado de bucles al rendimiento en diferentes cargas de trabajo.
2. Gráfico Comparativo por Tamaño del Array
Eje X: Tamaño del array.
Eje Y: Tiempo de ejecución en segundos.
Descripción: Alterna el tamaño del array (N) manteniendo el número de iteraciones constante. Este gráfico te permitirá observar cómo la eficiencia del desenrollado de bucles puede variar con diferentes tamaños de datos.
3. Histograma de Mejora de Rendimiento
Eje X: Tamaño del array o número de iteraciones.
Eje Y: Porcentaje de mejora en el tiempo de ejecución.
Descripción: Calcula el porcentaje de mejora en el tiempo usando la fórmula 
(
tiempo sin desenrollar
−
tiempo con desenrollar
)
/
tiempo sin desenrollar
×
100
%
(tiempo sin desenrollar−tiempo con desenrollar)/tiempo sin desenrollar×100%. Este gráfico muestra directamente el beneficio del desenrollado de bucles.
4. Gráfico de Tiempo Real versus Tiempo de CPU
Eje X: Número de iteraciones o tamaño del array.
Eje Y: Tiempo real versus tiempo de CPU.
Descripción: Compara el tiempo real (wall-clock time) y el tiempo de CPU para ambos métodos de ejecución del bucle. Este análisis puede ser relevante si el desenrollado del bucle afecta de manera diferente estos dos tipos de tiempo debido a la utilización del procesador y la gestión del sistema operativo.
5. Gráfico de Dispersión de Eficiencia de Caché
Eje X: Número de iteraciones o tamaño del array.
Eje Y: Tiempo de ejecución.
Descripción: Utiliza datos del uso de la caché o misses de caché (si disponibles mediante herramientas de perfilado como Valgrind o hardware counters) y compáralos con el tiempo de ejecución. Este gráfico puede ayudar a visualizar la relación entre la eficiencia de la caché y el rendimiento del bucle.