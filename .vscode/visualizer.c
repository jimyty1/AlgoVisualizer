#include <stdio.h>
#include "visualizer.h"


void log_swap(int arr[], int n, int i, int j)
{
    printf("{\"type\":\"swap\",\"i\":%d,\"j\":%d,\"array\":[",i,j);

    for(int x=0;x<n;x++)
    {
        printf("%d", arr[x]);

        if(x < n-1)
            printf(",");
    }

    printf("]}\n");
}


void log_compare(int arr[], int n, int i, int j)
{
    printf("{\"type\":\"compare\",\"i\":%d,\"j\":%d,\"array\":[",i,j);

    for(int x=0;x<n;x++)
    {
        printf("%d", arr[x]);

        if(x < n-1)
            printf(",");
    }

    printf("]}\n");
}