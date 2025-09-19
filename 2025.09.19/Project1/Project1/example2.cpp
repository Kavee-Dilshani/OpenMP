    
    #include <stdio.h>
    #include <omp.h>  

    int main() {
       int i;
        omp_set_num_threads(4);

        #pragma omp parallel for
        for (i = 0; i < 14; i++) {
            printf("Thread %d working on iteration %d\n", omp_get_thread_num(), i);
        }

        return 0;
    }

