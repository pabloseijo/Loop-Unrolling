#include <stdio.h>

int main(int argc , char *argv[]) {
    
    if(argc < 2){
        printf("ERROR: wrong number of arguments | Usage: %s <array size> <no. of iterations>\n", argv[0]);
        exit(1);
    }

    int N = atoi(argv[1]);
    int ITER = atoi(argv[2]);

    int i, k;
    float x[N], y[N];
    float a = 0.0, a1 = 0.0, a2 = 0.0, a3 = 0.0;

    //----- Fragmentos de codigo a medir -----//

    for(k=0; k<ITER; k++){
        a=0.0;
        for(i=0; i<N; i++)
        a = a + x[i] * y[i];
    }


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

}