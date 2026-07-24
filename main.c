#include <stdio.h>
#include "sortingalgos.h"


int main() {
    printf("running \n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n-1; i++){
        printf(" %d, ", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, n);
    for (int i = 0; i < n-1; i++){
        printf(" %d, ", arr[i]);
    }
    return 0;
}