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

int main(int argc , char *argv[]) {
    
    if(argc < 2){
        printf("ERROR: wrong number of arguments | Usage: %s <array size> <no. of iterations>\n", argv[0]);
        exit(1);
    }

    struct timeval start, end;

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

    long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

    printf("Bucle sin desenrrollar: %ld segundos y %ld microsegundos\n", seconds, micros);


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

    seconds = (end.tv_sec - start.tv_sec);
    micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

    printf("Bucle sin desenrrollar: %ld segundos y %ld microsegundos\n", seconds, micros);
}