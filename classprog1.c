#include <stdio.h>
#include <omp.h>

int main() {
    int p, m;
    
    p = omp_get_num_procs();
    m = omp_get_max_threads();

    printf("The number of processors: %d\n", p);
    printf("The maximum number of threads: %d\n", m);
    
    return 0;
}
