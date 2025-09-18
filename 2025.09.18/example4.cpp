#include <stdio.h>
#include <omp.h>

long N = 100000000;
double dx;

const int nt = 4;

int main()
{
	double pi = 0.0, sum[nt] = { 0.0 };
	double start_time, run_time;

	dx = 1.0 / (double)N;

	start_time = omp_get_wtime();

#pragma omp parallel num_threads(nt)
	{
		int myId = omp_get_thread_num();
		int i;
		double x , sum = 0.0;

		for (i = myId; i < N; i += nt) {
			x = (i + 0.5) * dx;
			sum += 4.0 / (1.0 + x * x);
		}

		#pragma omp critical
	}

	for (int j = 0; j < nt; j++)
		pi += sum[j] * dx;

	run_time = omp_get_wtime() - start_time;
	printf("\n pi with %ld steps is %lf in %lf seconds\n ", N, pi, run_time);
}