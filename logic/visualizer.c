#include <stdio.h>
#include "visualizer.h"

void print_array_json(int arr[], int n)
{
    printf("[");

    for (int x = 0; x < n; x++)
    {
        printf("%d", arr[x]);

        if (x < n - 1)
            printf(",");
    }

    printf("]");
}
void log_swap(int arr[], int n, int i, int j)
{
    printf("{\"type\":\"swap\",\"i\":%d,\"j\":%d,\"array\":", i, j);

    print_array_json(arr, n);

    printf("}\n");
}

void log_partition(int arr[], int n, int start, int end, int pivot, int boundary, int j)
{
    printf("{\"type\":\"partition\",\"start\":%d,\"end\":%d,\"pivot\":%d,\"boundary\":%d,\"j\":%d,\"array\":",
        start, end, pivot, boundary, j);

    print_array_json(arr, n);

    printf("}\n");
}
void log_pivot_placed(int arr[], int n, int pivot)
{
    printf(
        "{\"type\":\"pivot_placed\",\"index\":%d,\"array\":",
        pivot);

    print_array_json(arr, n);

    printf("}\n");
}

void log_compare(int arr[], int n, int i, int j)
{
    printf("{\"type\":\"compare\",\"i\":%d,\"j\":%d,\"array\":", i, j);

    print_array_json(arr, n);

    printf("}\n");
}
void log_compare_value(int arr[], int n, int i, int value)
{
    printf("{\"type\":\"compare_value\",\"i\":%d,\"value\":%d,\"array\":", i, value);

    print_array_json(arr, n);

    printf("}\n");
}
void log_merge_start(int arr[], int n, int start, int mid, int end)
{
    printf("{\"type\":\"merge_start\",\"start\":%d,\"mid\":%d,\"end\":%d,\"array\":", 
        start, mid, end);
        

    print_array_json(arr, n);

    printf("}\n");
}

void log_merge_compare(int arr[],int n,int left,int right,int start,int mid,int end)
{
    printf("{\"type\":\"merge_compare\",\"left\":%d,\"right\":%d,\"start\":%d,\"mid\":%d,\"end\":%d,\"array\":", 
        left, right, start, mid, end);
        

    print_array_json(arr, n);

    printf("}\n");
}

void log_overwrite(int arr[], int n, int index, int value)
{
    printf("{\"type\":\"overwrite\",\"index\":%d,\"with value\":%d,\"array\":", index, value);

    print_array_json(arr, n);

    printf("}\n");
}

void log_pivotB(int arr[], int n, int pivot, int boundary, int j)
{
    printf("{\"type\":\"pivot\",\"index\":%d,\"array\":", pivot);
    print_array_json(arr, n);
    printf("}\n");

    // Array
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("%4d", arr[i]);
    }
    printf("\n");

    // Boundary
    printf("B ");
    for (int i = 0; i < n; i++)
    {
        if (i == boundary)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n");

    // j
    printf("j ");
    for (int i = 0; i < n; i++)
    {
        if (i == j)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n");

    // Pivot
    printf("P ");
    for (int i = 0; i < n; i++)
    {
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

    if (left >= heapSize)
        left = -1;

    if (right >= heapSize)
        right = -1;

    printf(
        "{\"type\":\"heapify\",\"root\":%d,\"left\":%d,\"right\":%d,\"heapSize\":%d,\"array\":",
        root, left, right, heapSize);

    print_array_json(arr, n);
    printf("}\n");

}
void log_heapify_cliDrawn(int arr[], int n, int root, int heapSize)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left >= heapSize)
        left = -1;

    if (right >= heapSize)
        right = -1;

    // Array
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("%4d", arr[i]);
    }
    printf("\n");

    // Root
    printf("R ");
    for (int i = 0; i < n; i++)
    {
        if (i == root)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n");

    // Left
    printf("L ");
    for (int i = 0; i < n; i++)
    {
        if (i == left)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n");

    // Right
    printf("R ");
    for (int i = 0; i < n; i++)
    {
        if (i == right)
            printf("   ^");
        else
            printf("    ");
    }
    printf("\n\n");
}