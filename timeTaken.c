#include <stdio.h>
#include <omp.h>

int main() {
    double start = omp_get_wtime();

    #pragma omp parallel for
    for(int i = 0; i < 100000000; i++); // dummy loop

    double end = omp_get_wtime();
    printf("Time taken = %f seconds\n", end - start);
    return 0;
}
