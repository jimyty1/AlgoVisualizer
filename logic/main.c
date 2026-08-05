#include <stdio.h>
#include "sortingalgos.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s <algorithm> <numbers...>\n", argv[0]);
        return 1;
    }

    char *algorithm = argv[1];
    int n = argc - 2;

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 2]);
    }


    if (strcmp(algorithm, "bubble") == 0) {
    bubble_sort(arr, n);
    }
    else if (strcmp(algorithm, "selection") == 0) {
        selection_sort(arr, n);
    }
    else if (strcmp(algorithm, "insertion") == 0) {
        insertion_sort(arr, n);
    }
    else if (strcmp(algorithm, "merge") == 0) {
        merge_sort(arr, 0, n - 1, n);
    }
    else if (strcmp(algorithm, "quick") == 0) {
        quick_sort(arr, 0, n - 1, n);
    }
    else if (strcmp(algorithm, "heap") == 0) {
        heap_sort(arr, n);
    }
    else {
        printf("Unknown algorithm '%s'\n", algorithm);
        return 1;
    }

    printf("{\"type\":\"done\",\"array\":[");

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        if (i != n - 1)
            printf(",");
    }

    printf("]}\n");
}