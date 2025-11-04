#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    long long sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum of first %d natural numbers = %lld\n", n, sum);
    return 0;
}
