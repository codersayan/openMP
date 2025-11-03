#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    long long sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += (long long)i * i;
    }

    printf("Sum of squares from 1 to %d is: %lld\n", n, sum);

    return 0;
}
