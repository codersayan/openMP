#include <stdio.h>
#include <omp.h>

int main() {
    int A[5];
    int B[5] = {1, 2, 3, 4, 5};
    int C[5] = {1, 2, 3, 4, 5};
    int i, m;

    omp_set_dynamic(0);             // Disable dynamic adjustment of threads
    m = omp_get_num_procs();        // Get number of CPU cores
    omp_set_num_threads(m);         // Use that many threads

    #pragma omp parallel for
    for (i = 0; i < 5; i++) {
        A[i] = B[i] + C[i];  // Parallel computation

        printf("Thread %d of %d computed: A[%d] = %d + %d = %d\n",
               omp_get_thread_num(), omp_get_num_threads(),
               i, B[i], C[i], A[i]);
    }

    printf("\nFinal Array A:\n");
    for (i = 0; i < 5; i++)
        printf("A[%d] = %d\n", i, A[i]);

    return 0;
}
