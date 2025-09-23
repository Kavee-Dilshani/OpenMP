#include <stdio.h>
#include <omp.h>

#define N 20

int main() {
    int arr[N];

    // Parallel for loop to set arr[i] = i
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    // Only the master thread prints the array
#pragma omp master
    {
        printf("Array elements:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
