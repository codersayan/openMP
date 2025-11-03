#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_dynamic(1);
    omp_set_num_threads(6);

    #pragma omp parallel
    printf("\nHello from thread number: %d of total of %d threads\n",
           omp_get_thread_num(), omp_get_num_threads());

    return 0;
}

