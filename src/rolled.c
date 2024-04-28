/**
 * @file rolled.c
 * @details this is a modified version of the unrolled.c file, where the loop unrolling has been removed.
*/

//TODO: REVISAR LOS DATOS DE LOS CSV, ESTÁN MAL, ESTAN BIEN EN LOS TXT

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Función para limpiar la caché
void clearCache();

int main(int argc , char *argv[]) {
    
    if(argc < 2){
        printf("ERROR: wrong number of arguments | Usage: %s <array size> <no. of iterations>\n", argv[0]);
        exit(1);
    } 

    // Es necesario introducir la limpieza de la caché (y asi eliminar residuos) para obtener resultados más precisos
    clearCache(); 

    struct timeval start, end;
    clock_t start_cpu, end_cpu; // Variables para medir el tiempo de CPU

    int N = atoi(argv[1]);
    int ITER = atoi(argv[2]);

    int i, k;
    float x[N], y[N];
    float a = 0.0, a1 = 0.0, a2 = 0.0, a3 = 0.0;

    //----- Fragmentos de codigo a medir -----//

    gettimeofday(&start, NULL);

    for(k=0; k<ITER; k++){
        a=0.0;
        for(i=0; i<N; i++){
            a = a + x[i] * y[i];
        }
    }

    gettimeofday(&end, NULL);

    double tiempoSinDesenrollar = (end.tv_sec-start.tv_sec+(end.tv_usec-start.tv_usec)/1.e6);

    printf("Bucle normal - Tiempo real: %lf, tamaño: %d\n", tiempoSinDesenrollar, N);
}

void clearCache() {

    // Tamaño de la caché L1 de datos (L1d) en bytes
    int cacheSize = 64 * 1024;
    int numInts = cacheSize / sizeof(int); 
    int* dummy = malloc(numInts * sizeof(int));

    // Escribir en la memoria para asegurar que se carga en la caché L1 de datos
    for (int i = 0; i < numInts; i++) {
        dummy[i] = i;
    }

    free(dummy);
}
