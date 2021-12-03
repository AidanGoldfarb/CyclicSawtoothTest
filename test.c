#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h> 

unsigned long long M;
int R = 25;

void cyclic(int *arr, int r);
void sawtooth(int *arr, int r);

int main(int argc, char **argv){
    assert(argc == 2);
    M = atoi(argv[1]);
    int *arr = malloc(M*sizeof(int));
    if(!arr){printf("malloc\tfail\n");exit(0);}
    
    clock_t start = clock();
    cyclic(arr, R);
    clock_t end = clock();
    double rt = (double)(end-start)/CLOCKS_PER_SEC;
    fprintf(stdout,"%lld\t%f\n",M,rt);
}

void cyclic(int *arr, int reps){
    unsigned long long i;
    while(reps-- > 0){
        for(i = 0; i<M; i++){
            arr[i] = 1;
        }
        for(i = 0; i<M; i++){
            arr[i] = 1;
        }
    }
    
}

void sawtooth(int *arr, int reps){
    unsigned long long i;
    while(reps-- > 0){
        for(i = 0; i<M; i++){
            arr[i] = 1;
        }
        for(i = M-1; i>0; i--){
            arr[i] = 1;
        }
    }
}