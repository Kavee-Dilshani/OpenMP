#include <stdio.h>
#include <omp.h>

int main() {
    int shared_variable = 0;

    double start_time = omp_get_wtime(); // Start timing

#pragma omp parallel num_threads(8)
    {
        long local_sum = 0;
        for (int i = 0; i < 1000000; i++) {
        
            local_sum++;
        }
        #pragma omp critical
        shared_variable += local_sum;
    }

    double end_time = omp_get_wtime(); // End timing

    printf("Final value of shared_variable is %d.\n", shared_variable);
    printf("Runtime: %f seconds\n", end_time - start_time); // Calculate and print runtime

    return 0;
}