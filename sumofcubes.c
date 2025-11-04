#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    long long sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += (long long)i * i * i;
    }

    printf("Sum of cubes from 1 to %d = %lld\n", n, sum);
    return 0;
}
