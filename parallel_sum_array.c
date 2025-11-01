#include <stdio.h>
#include <omp.h>

int main() {
    int arr[8] = {1,2,3,4,5,6,7,8};
    int sum = 0, i;

    #pragma omp parallel for reduction(+:sum)
    for(i = 0; i < 8; i++) {
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);
    return 0;
}
