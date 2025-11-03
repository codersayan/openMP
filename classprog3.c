#include <stdio.h>
#include <omp.h>

int main() {
    int A[10] = {1,2,3,4,5,6,7,8,9,10}, i, m;

    omp_set_dynamic(0);  // disable dynamic thread adjustment

    m = omp_get_num_procs();  // get number of available CPU cores
    omp_set_num_threads(m);   // set the number of threads = number of CPU cores

    #pragma omp parallel for
    for (i = 0; i < 10; i++) {
        printf("\nHello from thread %d of %d",
               omp_get_thread_num(), omp_get_num_threads());
    }
}
