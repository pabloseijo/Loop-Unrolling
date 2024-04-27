/**
 * @file unrolling.c
 * @brief The objective of this file is to compare the performance of a loop with and without loop unrolling.
 * @details The program receives two arguments, the size of the array and the number of iterations. The program 
 *          calculates the dot product of two arrays of size N, and measures the time it takes to perform the 
 *          operation with and without loop unrolling.
*/

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

    FILE *f;

    if((f = fopen("times.csv", "a"))== NULL){
        printf("ERROR: file opening failed\n");
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

    start_cpu = clock();
    gettimeofday(&start, NULL);

    for(k=0; k<ITER; k++){
        a=0.0;
        for(i=0; i<N; i++){
            a = a + x[i] * y[i];
        }
    }

    gettimeofday(&end, NULL);
    end_cpu = clock();

    double tiempoSinDesenrollar = (end.tv_sec-start.tv_sec+(end.tv_usec-start.tv_usec)/1.e6);
    double tiempoSinDesenrrollarCpu = ((double) (end_cpu - start_cpu)) / CLOCKS_PER_SEC;

     printf("Bucle normal - Tiempo real: %lf, Tiempo CPU: %lf\n", tiempoSinDesenrollar, tiempoSinDesenrrollarCpu);

    //Para asegurarnos que las mediciones no esten afectadas por la carga anterior, limpiamos la cache
    clearCache();

    start_cpu = clock();
    gettimeofday(&start, NULL);

    for(k=0; k<ITER; k++){
        a = a1 = a2 = a3 = 0.0;

        for(i=0; i<N; i+=4){
            a = a + x[i] * y[i];
            a1 = a1 + x[i+1] * y[i+1];
            a2 = a2 + x[i+2] * y[i+2];
            a3 = a3 + x[i+3] * y[i+3];
        }   

        a = a + a1 + a2 + a3;
    } 

    gettimeofday(&end, NULL);
    end_cpu = clock();

    double tiempoDesenrrollado = (end.tv_sec-start.tv_sec+(end.tv_usec-start.tv_usec)/1.e6);
    double tiempoDesenrrolladoCpu = ((double) (end_cpu - start_cpu)) / CLOCKS_PER_SEC;

    printf("Bucle desenrollado - Tiempo real: %lf, Tiempo CPU: %lf\n", tiempoDesenrrollado, tiempoDesenrrolladoCpu);

    // Escribir los resultados en el archivo CSV
    fprintf(f, "%d, %lf, %lf, %lf, %lf\n", N, tiempoSinDesenrollar, tiempoSinDesenrrollarCpu, tiempoDesenrrollado, tiempoDesenrrolladoCpu);
    
    fclose(f);
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
