#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "sortingalgos.h"

#define VERBOSE 0    // Set to 0 to disable verbose output

/*
 * Prints an array in the format [1, 2, 3]
 */
void print_array(int arr[], int n) {
    printf("[");

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]");
}

/*
 * Prints the original array and the sorted result.
 */
void verbose_print(const char *test_name, int before[], int after[], int n) {
    if (!VERBOSE)
        return;

    printf("\n%s\n", test_name);

    printf("Before: ");
    print_array(before, n);

    printf("\nAfter : ");
    print_array(after, n);

    printf("\n");
}

/*
 * Returns 1 if arrays are equal, 0 otherwise.
 */
int assert_array_equal(int actual[], int expected[], int n) {

    for (int i = 0; i < n; i++) {
        if (actual[i] != expected[i])
            return 0;
    }

    return 1;
}
void run_sort_tests(void (*sort)(int[], int), const char *name) {

    printf("\n==============================\n");
    printf("%s\n", name);
    printf("==============================\n");

    // Random array
    {
        int arr[] = {64,34,25,12,22,11,90};
        int before[] = {64,34,25,12,22,11,90};
        int expected[] = {11,12,22,25,34,64,90};

        sort(arr,7);

        verbose_print("Random Array", before, arr, 7);

        assert(assert_array_equal(arr, expected, 7));
    }

    // Already sorted
    {
        int arr[] = {1,2,3,4,5,6};
        int before[] = {1,2,3,4,5,6};
        int expected[] = {1,2,3,4,5,6};

        sort(arr,6);

        verbose_print("Already Sorted", before, arr, 6);

        assert(assert_array_equal(arr, expected, 6));
    }

    // Reverse sorted
    {
        int arr[] = {6,5,4,3,2,1};
        int before[] = {6,5,4,3,2,1};
        int expected[] = {1,2,3,4,5,6};

        sort(arr,6);

        verbose_print("Reverse Sorted", before, arr, 6);

        assert(assert_array_equal(arr, expected, 6));
    }

    // Duplicates
    {
        int arr[] = {5,1,3,3,2,5,1};
        int before[] = {5,1,3,3,2,5,1};
        int expected[] = {1,1,2,3,3,5,5};

        sort(arr,7);

        verbose_print("Duplicates", before, arr, 7);

        assert(assert_array_equal(arr, expected, 7));
    }

    // Negative numbers
    {
        int arr[] = {-3,7,-1,4,-8,0};
        int before[] = {-3,7,-1,4,-8,0};
        int expected[] = {-8,-3,-1,0,4,7};

        sort(arr,6);

        verbose_print("Negative Numbers", before, arr, 6);

        assert(assert_array_equal(arr, expected, 6));
    }

    // Single element
    {
        int arr[] = {42};
        int before[] = {42};
        int expected[] = {42};

        sort(arr,1);

        verbose_print("Single Element", before, arr, 1);

        assert(assert_array_equal(arr, expected, 1));
    }

    // Empty array
    {
        int arr[] = {};

        sort(arr,0);

        if (VERBOSE)
            printf("\nEmpty Array\nBefore: []\nAfter : []\n");
    }

    // All equal
    {
        int arr[] = {9,9,9,9,9};
        int before[] = {9,9,9,9,9};
        int expected[] = {9,9,9,9,9};

        sort(arr,5);

        verbose_print("All Equal", before, arr, 5);

        assert(assert_array_equal(arr, expected, 5));
    }

    printf("\n%s PASSED\n\n", name);
}
/*
 * Tests Merge Sort.
 * Uses start/end indexes instead of array length.
 */
void merge_sort_test() {

    printf("\n==============================\n");
    printf("Merge Sort\n");
    printf("==============================\n");

    {
        int arr[] = {64,34,25,12,22,11,90};
        int before[] = {64,34,25,12,22,11,90};
        int expected[] = {11,12,22,25,34,64,90};

        merge_sort(arr,0,6);

        verbose_print("Random Array", before, arr, 7);

        assert(assert_array_equal(arr, expected, 7));
    }

    {
        int arr[] = {5,4,3,2,1};
        int before[] = {5,4,3,2,1};
        int expected[] = {1,2,3,4,5};

        merge_sort(arr,0,4);

        verbose_print("Reverse Sorted", before, arr, 5);

        assert(assert_array_equal(arr, expected, 5));
    }

    {
        int arr[] = {-5,2,-1,4,-8};
        int before[] = {-5,2,-1,4,-8};
        int expected[] = {-8,-5,-1,2,4};

        merge_sort(arr,0,4);

        verbose_print("Negative Numbers", before, arr, 5);

        assert(assert_array_equal(arr, expected, 5));
    }

    printf("\nMerge Sort PASSED\n");
}


/*
 * Tests Quick Sort.
 * Uses start/end indexes instead of array length.
 */
void quick_sort_test() {

    printf("\n==============================\n");
    printf("Quick Sort\n");
    printf("==============================\n");

    {
        int arr[] = {64,34,25,12,22,11,90};
        int before[] = {64,34,25,12,22,11,90};
        int expected[] = {11,12,22,25,34,64,90};

        quick_sort(arr,0,6);

        verbose_print("Random Array", before, arr, 7);

        assert(assert_array_equal(arr, expected, 7));
    }

    {
        int arr[] = {3,3,3,2,1,2,3};
        int before[] = {3,3,3,2,1,2,3};
        int expected[] = {1,2,2,3,3,3,3};

        quick_sort(arr,0,6);

        verbose_print("Duplicates", before, arr, 7);

        assert(assert_array_equal(arr, expected, 7));
    }

    {
        int arr[] = {-5,2,-1,4,-8};
        int before[] = {-5,2,-1,4,-8};
        int expected[] = {-8,-5,-1,2,4};

        quick_sort(arr,0,4);

        verbose_print("Negative Numbers", before, arr, 5);

        assert(assert_array_equal(arr, expected, 5));
    }

    printf("\nQuick Sort PASSED\n");

}

int main() {

    run_sort_tests(bubble_sort, "Bubble Sort");
    run_sort_tests(insertion_sort, "Insertion Sort");
    run_sort_tests(selection_sort, "Selection Sort");
    run_sort_tests(heap_sort, "Heap Sort");

    merge_sort_test();
    quick_sort_test();

    printf("\n=====================================\n");
    printf("All sorting algorithm tests passed!\n");
    printf("=====================================\n");

    return 0;
}