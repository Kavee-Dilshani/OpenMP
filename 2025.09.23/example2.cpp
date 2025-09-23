#include <stdio.h>
#include <omp.h>

int main() {
    long sum = 0;	//Shared variable

    double start_time = omp_get_wtime(); // Start timing

/*#pragma omp parallel num_threads(8)
    {
        long local_sum = 0;






        for (int i = 0; i < 1000000; i++) {
            //#pragma omp critical   // in critical section calculate sum in serial way. so i is not want in for loop. the time is high
           // sum++;
            local_sum++;
        }

     #pragma omp critical        //result is 8000000
        sum = sum + local_sum;
    }

    */

    //----------------------------------if we use parallel for no need local variable-----------------------------------


        
    #pragma omp parallel num_threads(8)
    {

    /*long local_sum = 0;

    #pragma omp for
        for (int i = 0; i < 8000000; i++) {

        local_sum++;
    }

    #pragma omp critical        //result is 8000000
        sum = sum + local_sum;

    */

    #pragma omp for reduction(+:sum)

        for (int i = 0; i < 8000000; i++) {

            sum++;
        }


    }

    double end_time = omp_get_wtime(); // End timing

    printf("Final value of shared_variable is %ld.\n", sum);
    printf("Runtime: %f seconds\n", end_time - start_time); // Calculate and print runtime

    return 0;
}


/* for (i = 1 : 8)
    parralel

    for()
    serial
    */