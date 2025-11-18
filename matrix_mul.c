#include <stdio.h>
#include <omp.h>

int main() {
	int A[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int B[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int C[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	
	int i,j,k;
	
	#pragma omp parallel for private(i,j,k) shared(A,B,C)
	for(i=0;i<3;++i)
		for(j=0;j<3;++j)
			for(k=0;k<3;++k)
				C[i][j] += A[i][k] * B[k][j];
	
	int m,n;
	
	for(m = 0; m < 3; m++){
		for(n = 0; n < 3; n++)
			printf("%d ", C[m][n]);
		printf("\n");
	}
	
	return 0;
}