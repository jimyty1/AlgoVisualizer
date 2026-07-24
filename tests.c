#include <stdio.h>
#include <assert.h>
#include "sortingalgos.h"

void bubble_sort_test(){
    // Test cases for bubble sort
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};

    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("arr[%d] = %d, expected[%d] = %d\n", i, arr[i], i, expected[i]);
        assert(arr[i] == expected[i]);
    }
    printf("Bubble sort test passed!\n");
}

int main() {
    bubble_sort_test();
    printf("All tests passed!\n");
    return 0;
}