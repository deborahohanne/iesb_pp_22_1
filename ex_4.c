#include <stdio.h>
#include <stdlib.h>

#include "omp.h"

float res;

float B;
int i, id, nthrds;
nthrds = omp_get_num_threads();

for(i=id; i<niters;i+=nthrds){
    B = big_jib(i);

    res += consume(B);
}
