#include <omp.h>
#include <stdio.h>
/*
const int nthread = 4;
int main() {
	int nrows = 10;  // More rows than threads
	int ncols = 3;
	int matrix[10][3] = { {1, 0, 1}, {0, 1, 0}, {1, 1, 0}, {0, 0, 1},
						 {1, 1, 1}, {0, 1, 1}, {1, 0, 0}, {1, 1, 0},
						 {0, 0, 1}, {1, 0, 1} };
	int vector[3] = { 1, 2, 3 };
	int result[10] = { 0 };

	omp_set_num_threads(nthread);

#pragma omp parallel
	{
		int myid = omp_get_thread_num();

		// Write your code here

		for (int i = myid; i < nrows; i = i + nthread) {
			for (int j = 0; j < ncols; j++)
				result[i] += matrix[i][j] * vector[j];



			printf("\n Thread %d >>>>> result[%d] = %d", myid, myid, result[i]);
		}
		
	}
	return 0;
}
*/

//=======================================================================================

/*int main() {

	//int myid;

#pragma omp parallel num_threads(24)
	{
	int myid = omp_get_thread_num();

	#pragma omp barrier

	printf("\n Iam %d", myid);

	}

	return 0;
}

*/

//==========================================================================================


/*int main() {
	int shared_variable[8] = { 0 };

	double start_time = omp_get_wtime(); // Start timing

#pragma omp parallel num_threads(8)
	{
		int myid = omp_get_thread_num();

		for (int i = 0; i < 100000000; i++) {
			shared_variable[myid][0]++;
		}

		int final_sum = 0;
		for (int k = 0; k < 8; k++)
			final_sum += shared_variable[k][0];
	}

	double end_time = omp_get_wtime(); // End timing

	printf("Final value of shared_variable is %d.\n", shared_variable[myid]);
	printf("Runtime: %f seconds\n", end_time - start_time); // Calculate and print runtime

	return 0;
}
*/

int main() {
	int shared_variable[8][8] = { {0} };

	double start_time = omp_get_wtime(); // Start timing

#pragma omp parallel num_threads(8)
	{
		int myid = omp_get_thread_num();

		for (int i = 0; i < 100000000; i++) {
			shared_variable[myid][0]++;
		}

		int final_sum = 0;
		for (int k = 0; k < 8; k++)
			final_sum += shared_variable[k][0];
	}

	double end_time = omp_get_wtime(); // End timing

	printf("Final value of shared_variable is %d.\n", shared_variable);
	printf("Runtime: %f seconds\n", end_time - start_time); // Calculate and print runtime

	return 0;
}
