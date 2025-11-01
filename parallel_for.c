#include <stdio.h>
#include <omp.h>

int main() {
    int i;
    #pragma omp parallel for
    for(i = 0; i < 8; i++) {
        printf("Iteration %d handled by thread %d\n", 
               i, omp_get_thread_num());
    }
    return 0;
}
