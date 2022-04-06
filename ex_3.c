#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define NUM_THREADS 2

static long num_steps = 10;
double step;

int main ()
{
    double t1,t2;
    int i; double x, pi, sum = 0.0;

    t1 = omp_get_wtime();
    step = 1.0/(double) num_steps;
    for (i=0;i< num_steps; i++){
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }


    pi = step * sum;

    omp_set_num_threads(NUM_THREADS);

    t2 = omp_get_wtime();
    printf("\n PI: %lf",pi);
    printf("\n Tempo gasto: %lf",t2-t1);
    printf("\n");
}
