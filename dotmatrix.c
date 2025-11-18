#include <stdio.h>
#include <omp.h>

int main() {
	int A[3] = {1, 2, 3};
	int B[3] = {4, 5, 7};
	int cross_product[3] = {0, 0, 0};
	int dot_product = 0;
	int i,j,x;
	
	
	
	//Dot Product
	#pragma omp parallel for reduction (+:dot_product)
	for(i=0;i<3;++i)
		dot_product += A[i] * B[i];



	//Print Dot Product
	printf("\nDot Product = %d \n", dot_product);
	
	
	
	//Cross Product	
	#pragma omp parallel for private(x) shared(A,B,cross_product)
	for(j = 0; j < 3; ++j){
		cross_product[j] = A[(j+1)%3] * B[(j+2)%3] - B[(j+1)%3] * A[(j+2)%3];
	}


	
	//Print Cross Product
	printf("\n");
	for(x = 0; x < 3; ++x)
		printf("\nCross product = %d \n ", cross_product[x]);
	printf("\n");
	
	
	
	
	
	return 0;
}