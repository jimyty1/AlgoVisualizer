#include <stdio.h>
#include "sortingalgos.h"

// taking arr and size as c turns the array into a pointer and the size of the array is lost. 
// So we need to pass the size of the array as well.

void bubble_sort(int arr[], int n) {
    // Implementation of bubble sort algorithm
    int swap = 1;
    while (swap != 0){
        swap = 0;
        for(int i = 0; i < n-1; i++){
            if (i > (i+1)){
                printf("before , %d, %d", arr[i], arr[i+1]);
                int c = i;
                arr[i] = arr[i+1];
                arr[i+1] = arr[c];
                printf("after, %d, %d", arr[i], arr[i+1]);
                swap = 1;
            }
        }
    }
}