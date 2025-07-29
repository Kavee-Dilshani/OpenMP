//#include <omp.h>
//#include <stdio.h>
//
//
//int main() {
//    int x = 0;
//    printf("\n Initially, x = %d", x);
//
//    omp_set_num_threads(4);
//
//#pragma omp parallel
//    {
// int myid = omp_get_thread_num();
//        int num = omp_get_num_threads();
//
//        x = x + myid;
//        printf("\n Thread %d of %d ",myid, num);
//    }
//
//    return 0;
//}

//..........................................................................


//#include <omp.h>
//#include <stdio.h>
//
//int main() {
//    int a[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
//
//    omp_set_num_threads(8);  // Match the number of threads to the array size
//
//#pragma omp parallel
//    {
//        //You may use "omp_get_thread_num()" to find thread's ids
//        int myid = omp_get_thread_num();
//        //Complete this to set a[myid] = myid * myid, by each thread
//        a[myid] = myid +myid;
//        printf("\n Thread %d >>>>> a[%d] = %d", myid, myid, a[myid]);
//    }
//
//    return 0;
//}

//.............................................................................

//#include <omp.h>
//#include <stdio.h>
//
//int main() {
//    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//    int n = sizeof(a) / sizeof(a[0]);
//
//    omp_set_num_threads(4);
//
//#pragma omp parallel
//    {
//        //You may use "omp_get_num_threads()" and "omp_get_thread_num()" to find 
//        int num = omp_get_num_threads();
//        int myid = omp_get_thread_num();
//        // - the number of threads and thread's id 
//        // 
//        // Initialise the array values with a[i] += 10 in a round robin manner
//
//        for(int i =myid;i<n;i += num)
//        {
//            a[i] += 10;
//            printf("\n Thread %d >>>>> a[%d] = %d", myid, i, a[i]);
//
//       
//         }
//}
//
//return 0;
//}

//..................................................................................

#include <omp.h>
#include <stdio.h>

int main() {
    int nrows = 4;
    int cols = 3;
    int matrix[4][3] = { {1, 0, 1},
                            {1, 1, 0},
                            {1, 1, 1},
                            {0, 1, 1} };

    int vector[3] = { 1, 2, 3 };
    int result[4] = { 0 };

    omp_set_num_threads(4);

#pragma omp parallel
    {
        int myid = omp_get_thread_num();

        // result[myid] = ???;
        for (int i = 0; i < cols; i++)
        {
            result[myid] += matrix[myid][i] * vector[i];
           
        }
        
        printf("\n Thread %d >>>>> result[%d] = %d", myid, myid, result[myid]);
       
    }

    return 0;
}



