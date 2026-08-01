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


