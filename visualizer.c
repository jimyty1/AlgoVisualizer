#include <stdio.h>
#include "visualizer.h"

void print_array_json(int arr[], int n)
{
    printf("[");

    for(int x = 0; x < n; x++)
    {
        printf("%d", arr[x]);

        if(x < n-1)
            printf(",");
    }

    printf("]");
}
void log_swap(int arr[], int n, int i, int j)
{
    printf("{\"type\":\"swap\",\"i\":%d,\"j\":%d,\"array\":", i, j);

    print_array_json(arr,n);

    printf("}\n");
}


void log_compare(int arr[], int n, int i, int j)
{
    printf("{\"type\":\"compare\",\"i\":%d,\"j\":%d,\"array\":", i, j);

    print_array_json(arr,n);

    printf("}\n");
}

void log_overwrite(int arr[], int n, int index, int value)
{
    printf("{\"type\":\"overwrite\",\"index\":%d,\"with value\":%d,\"array\":", index, value);

    print_array_json(arr,n);

    printf("}\n");
}

void log_pivotB(int arr[], int n, int pivot, int boundary, int j)
{
    printf("{\"type\":\"pivot\",\"index\":%d,\"array\":", pivot);
    print_array_json(arr, n);
    printf("}\n");

    // Array
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    // Boundary
    printf("B ");
    for (int i = 0; i < n; i++) {
        if (i == boundary)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n");

    // j
    printf("j ");
    for (int i = 0; i < n; i++) {
        if (i == j)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n");

    // Pivot
    printf("P ");
    for (int i = 0; i < n; i++) {
        if (i == pivot)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n\n");
}
void log_heapify(int arr[], int n, int root, int heapSize)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if(left >= heapSize)
        left = -1;

    if(right >= heapSize)
        right = -1;

    printf(
        "{\"type\":\"heapify\",\"root\":%d,\"left\":%d,\"right\":%d,\"heapSize\":%d,\"array\":",
        root, left, right, heapSize
    );

    print_array_json(arr,n);
    printf("}\n");

    printf("      ");
    for(int i = 0; i < n; i++)
        printf("%4d", arr[i]);
    printf("\n");

    printf("Root  ");
    for(int i = 0; i < n; i++)
        printf(i == root ? "   ^" : "    ");
    printf("\n");

    printf("Left  ");
    for(int i = 0; i < n; i++)
        printf(i == left ? "   ^" : "    ");
    printf("\n");

    printf("Right ");
    for(int i = 0; i < n; i++)
        printf(i == right ? "   ^" : "    ");
    printf("\n");

    printf("Heap  ");
    for(int i = 0; i < n; i++)
        printf(i < heapSize ? " ---" : "    ");
    printf("\n\n");
}