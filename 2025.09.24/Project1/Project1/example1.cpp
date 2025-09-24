/*#include <stdio.h>
#include <omp.h>
#include <limits.h>

int main() {
	int n = 10;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sum = 0;


	//compute the sum of element
#pragma omp parallel for reduction(+:sum)
	for (int i = 0;i < n;i++) {
		sum += a[i];
	}

	printf("Sum of array: %d\n", sum);
	return 0;

	*/

//------------------------------------------------------------

	/*int n = 5;
	int x[5] = { 1,2,3,4,5 };
	int y[5] = { 10,20,30,40,50 };
	int result = 0;

	//Compute the dot product of two vectors

#pragma omp parallel for reduction(+:sum)
	for (int i = 0;i < n;i++) {
		result += x[i]* y[i];
	}
	printf("Dot product = %d\n", result);
	return 0;
}*/

//------------------------------------------

/*#include <stdio.h>
#include <omp.h>
#include <limits.h>

int main() {
	int n = 8;
	int a[8] = { 3, 7, 2, 9, 12, 5, 8, 4 };
	int maxVal = INT_MIN;

	//Find the maximum value

	#pragma omp parallel for reduction(max:maxVal)
	for (int i = 0;i < n;i++) 
		if (maxVal < a[i])
			maxVal = a[i];
	

	printf("Maximum value = %d\n", maxVal);
	return 0;
}*/

//-----------------------------------------------

/*#include <stdio.h>
#include <omp.h>

int main() {
	int n = 4;
	int A[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	int x[4] = { 1, 1, 1, 1 };
	int y[4] = { 0 };
	int sum = 0;
	// Compute y[4] = A[4][4] . x[4]

	#pragma omp parallel for 
	{
		for (int i = 0;i < n;i++) {
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
			sum += A[i][j] * x[j];
			}

		}

	}
	printf("Result vector: ");
	for (int i = 0; i < n; i++) printf("%d ", y[i]);
	printf("\n");
	return 0;
}*/

//------------------------------------------------------------

/*#include <stdio.h>
#include <omp.h>

int main() {
	int n = 6;
	double a[6] = { 2.0, 4.0, 4.0, 4.0, 5.0, 5.0 };
	double sum = 0.0, sumSq = 0.0, mean, variance;

	#pragma omp parallel for reduction(+:sum,sumSq)
	//Compute sum = sum of (a[i])
	for (int i = 0;i < n;i++) {
		sum += a[i];
		sumSq += (a[i] * a[i]);
	}

	mean = sum / n;
	variance = (sumSq / n) - (mean * mean);
	//Compute sumSq = sum of (a[i] * a[i])
	
	//Compute mean = sum / n
	//Compute variance = (sumSq / n) - (mean * mean)


	printf("Mean = %.2f, Variance = %.2f\n", mean, variance);
	return 0;
}*/

#include <stdio.h>
#include <omp.h>

long N = 100000000;
double dx;

int main()
{
	int i;
	double x, pi, sum = 0.0;
	double start_time, run_time;

	dx = 1.0 / (double)N;

	start_time = omp_get_wtime();

	#pragma omp parallel for reduction(+:sum)
	for (i = 0; i < N; i++) {
		x = (i + 0.5) * dx;
		sum += 4.0 / (1.0 + x * x);
	}

	pi = sum * dx;

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}