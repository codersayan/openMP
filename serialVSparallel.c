#include <stdio.h>
#include <omp.h>

int main() {
    double start, end;

    // Serial
    start = omp_get_wtime();
    for(int i = 0; i < 100000000; i++);
    end = omp_get_wtime();
    printf("Serial Time: %f seconds\n", end - start);

    // Parallel
    start = omp_get_wtime();
    #pragma omp parallel for
    for(int i = 0; i < 100000000; i++);
    end = omp_get_wtime();
    printf("Parallel Time: %f seconds\n", end - start);

    return 0;
}
