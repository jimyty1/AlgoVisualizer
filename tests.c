#include <stdio.h>
#include <assert.h>
#include "sortingalgos.h"

void print_test_result(
    int arr[],
    int expected[],
    int n,
    char debugStr
) {
    for (int i = 0; i < n; i++) {
        if (debugStr == 'y' || debugStr == 'Y') {
            printf(
                "arr[%d] = %d, expected[%d] = %d\n",
                i, arr[i], i, expected[i]
            );
        }

        assert(arr[i] == expected[i]);
    }
}

void bubble_sort_test(char debugStr) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);

    print_test_result(arr, expected, n, debugStr);

    printf("Bubble sort test passed!\n");
}

void insertion_sort_test(char debugStr) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    print_test_result(arr, expected, n, debugStr);

    printf("Insertion sort test passed!\n");
}

void selection_sort_test(char debugStr) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);

    print_test_result(arr, expected, n, debugStr);

    printf("Selection sort test passed!\n");
}

int main() {
    char algosDebug;

    printf("algosDebug? (y/n): ");
    scanf(" %c", &algosDebug);

    printf("\nChosen: %c\n\n", algosDebug);

    bubble_sort_test(algosDebug);
    insertion_sort_test(algosDebug);
    selection_sort_test(algosDebug);

    printf("\nAll tests passed!\n");

    return 0;
}