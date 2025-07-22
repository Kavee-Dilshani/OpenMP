#include <stdio.h>
#include <omp.h>
int main() {
	// Parallel region
	

	/*int num = omp_get_num_threads();
	printf("Number of threads are: %d\n", num);*/

	int x = 0;
	printf("\n Initially, x = %d", x);

	omp_set_num_threads(4);

	#pragma omp parallel
	{
		/*printf("Hello World!\n");*/

		//printf("Number of threads are: %d\n", omp_get_num_threads());

		int myid = omp_get_thread_num();
		//int thre = omp_get_num_threads();
		//printf("I am thread %d, Total number of threads: %d\n", myid,thre);

		x = x + myid;
		printf("\n Thread %d >>>>> x + myid = %d", myid, x);
	}
	return 0;
}