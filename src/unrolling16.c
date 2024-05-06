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
    
    if(argc < 3){
        printf("ERROR: wrong number of arguments | Usage: %s <array size> <no. of iterations>\n", argv[0]);
        exit(1);
    } 

    FILE *fp;   

    if((fp = fopen("unrolling16.csv", "a")) == NULL){
        printf("ERROR: opening the file failed\n");
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
    float a = 0.0, a1 = 0.0, a2 = 0.0, a3 = 0.0, a4 = 0.0, a5 = 0.0, a6 = 0.0, a7 = 0.0;
    float a8 = 0.0, a9 = 0.0, a10 = 0.0, a11 = 0.0, a12 = 0.0, a13 = 0.0, a14 = 0.0, a15 = 0.0;

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

    printf("Tiempo sin desenrollar - Tiempo real: %lf\n", tiempoSinDesenrollar);

    //Para asegurarnos que las mediciones no esten afectadas por la carga anterior, limpiamos la cache
    clearCache();

    gettimeofday(&start, NULL);

   for (k = 0; k < ITER; k++) {
        a = a1 = a2 = a3 = a4 = a5 = a6 = a7 = a8 = a9 = a10 = a11 = a12 = a13 = a14 = a15 = 0.0;

        for (i = 0; i < N; i += 16) {
            a = a + x[i] * y[i];
            a1 = a1 + x[i+1] * y[i+1];
            a2 = a2 + x[i+2] * y[i+2];
            a3 = a3 + x[i+3] * y[i+3];
            a4 = a4 + x[i+4] * y[i+4];
            a5 = a5 + x[i+5] * y[i+5];
            a6 = a6 + x[i+6] * y[i+6];
            a7 = a7 + x[i+7] * y[i+7];
            a8 = a8 + x[i+8] * y[i+8];
            a9 = a9 + x[i+9] * y[i+9];
            a10 = a10 + x[i+10] * y[i+10];
            a11 = a11 + x[i+11] * y[i+11];
            a12 = a12 + x[i+12] * y[i+12];
            a13 = a13 + x[i+13] * y[i+13];
            a14 = a14 + x[i+14] * y[i+14];
            a15 = a15 + x[i+15] * y[i+15];
        }

        a = a + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a10 + a11 + a12 + a13 + a14 + a15;
    }




    gettimeofday(&end, NULL);

    double tiempoDesenrollado = (end.tv_sec-start.tv_sec+(end.tv_usec-start.tv_usec)/1.e6);
    printf("Bucle desenrollado - Tiempo real: %lf\n", tiempoDesenrollado);

    // Escribir los resultados en el archivo CSV
    fprintf(fp, "%d, %lf, %lf\n", N, tiempoSinDesenrollar, tiempoDesenrollado);
    fclose(fp);  // Cerrar el archivo
}

//Limpia las caches del ordenador
void clearCache() {
    // Tamaños de las cachés en bytes
    int l1d_cacheSize_perf0 = 131072; // L1d perflevel0
    int l1d_cacheSize_perf1 = 65536;  // L1d perflevel1
    int l2_cacheSize_perf0 = 16777216; // L2 perflevel0
    int l2_cacheSize_perf1 = 4194304; // L2 perflevel1
    
    int cacheSizes[] = {l1d_cacheSize_perf0, l1d_cacheSize_perf1, l2_cacheSize_perf0, l2_cacheSize_perf1};
    int numSizes = sizeof(cacheSizes) / sizeof(int);
    int i, j;
    
    for (j = 0; j < numSizes; j++) {
        int numInts = cacheSizes[j] / sizeof(int);
        int* dummy = malloc(numInts * sizeof(int));
        
        // Escribir en la memoria para asegurar que se carga en la caché
        for (i = 0; i < numInts; i++) {
            dummy[i] = i;
        }
        
        free(dummy);
    }
}

