#include <stdio.h>
#include <assert.h>
#include "sortingalgos.h"

void bubble_sort_test(char debugStr) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);

    if (debugStr == 'y' || debugStr == 'Y') {
        for (int i = 0; i < n; i++) {
            printf(
                "arr[%d] = %d, expected[%d] = %d\n",
                i, arr[i], i, expected[i]
            );

            assert(arr[i] == expected[i]);
        }
    } else {
        for (int i = 0; i < n; i++) {
            assert(arr[i] == expected[i]);
        }
    }

    printf("\n Bubble sort test passed!\n");
}

void insertion_sort_test(char debugStr) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int expected[] = {11, 12, 22, 25, 34, 64, 90};

    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    if (debugStr == 'y' || debugStr == 'Y') {
        for (int i = 0; i < n; i++) {
            printf(
                "arr[%d] = %d, expected[%d] = %d\n",
                i, arr[i], i, expected[i]
            );

            assert(arr[i] == expected[i]);
        }
    } else {
        for (int i = 0; i < n; i++) {
            assert(arr[i] == expected[i]);
        }
    }

    printf("\n Insertion sort test passed!\n");
}

int main() {
    char bbsDebug , issDebug;

    printf("bbsDebug? (y/n): ");
    scanf(" %c", &bbsDebug);
    printf("\n chose %c ", bbsDebug);

    bubble_sort_test(bbsDebug);

    printf("issDebug? (y/n): ");
    scanf(" %c", &issDebug);
    printf("\n chose %c ", issDebug);

    bubble_sort_test(issDebug);

    printf("All tests passed!\n");

    return 0;
}