#!/bin/bash

# Iteraciones fijas
ITERATIONS=2000000

# Ejecutable
EXECUTABLE="./exe"

# Archivo de resultados
OUTPUT_FILE="unrolling16.csv"

# Escribir encabezado en el archivo de resultados
echo "N, tiempoSinDesenrollar, tiempoDesenrollado" > $OUTPUT_FILE

# Loop a través de los tamaños de array
for ((SIZE = 16; SIZE <= 8192; SIZE *= 2))
do
    echo "Running $EXECUTABLE with array size $SIZE and $ITERATIONS iterations..."
    $EXECUTABLE $SIZE $ITERATIONS
done

echo "All done. Results are saved in $OUTPUT_FILE."
