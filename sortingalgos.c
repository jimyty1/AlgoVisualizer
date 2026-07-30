#include <stdio.h>
#include "sortingalgos.h"

// taking arr and size as c turns the array into a pointer and the size of the array is lost. 
// So we need to pass the size of the array as well.

void swap(int arr[], int n, int i, int j)
{
    log_swap(arr, n, i, j);

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int compare(int arr[], int n, int i, int j)
{
    log_compare(arr, n, i, j);

    return arr[i] > arr[j];
}

void bubble_sort(int arr[], int n) {
    // Implementation of bubble sort algorithm
    int s = 1;
    while (s != 0){
        s = 0;
        for(int i = 0; i < n-1; i++){
            if (compare(arr, n, i, i+1)){
                swap(arr, n, i, i+1);
                s = 1;
            }
        }
    }
}

void insertion_sort(int arr[], int n){

    for (int i = 0; i < n; i++){
        int c = arr[i];
        int j = i;
        while(j>0 && c < arr[j - 1]){
            arr[j] = arr[j - 1];
            j --;
        }
        arr[j] = c;
    }
}

void selection_sort(int arr[], int n){
    for(int i = 0; i< n - 1; i++){
        int minI = i;
        for(int j = i; j< n; j++){
            if (arr[j] < arr[minI]){
                minI = j;
            }
        }
        int c = arr[i];
        arr[i] = arr[minI];
        arr[minI] = c;
    }
}
void merge(int arr[], int start, int mid, int end) {
    int q = start;
    int p = mid + 1;

    int A[end - start + 1];
    int k = 0;

    for (int i = start; i <= end; i++) {
        if (p > end) {
            A[k++] = arr[q++];
        }
        else if (q > mid) {
            A[k++] = arr[p++];
        }
        else if (arr[p] < arr[q]) {
            A[k++] = arr[p++];
        }
        else {
            A[k++] = arr[q++];
        }
    }

    for (int i = 0; i < k; i++) {
        arr[start + i] = A[i];
    }
}

void merge_sort(int arr[], int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);

        merge(arr, start, mid, end);
    }
    
}
void quick_sort(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int boundary = start;
    int pivot = end;
    for (int j = start; j < end; j++)
    {
        if(arr[j] < arr[pivot]){            
            int c = arr[j];
            arr[j]= arr[boundary];
            arr[boundary] = c;
            boundary++;
        }
    }
    int t = arr[pivot];
    arr[pivot] = arr[boundary];
    arr[boundary] = t;
    quick_sort(arr, start, boundary - 1);
    quick_sort(arr, boundary+1, end);
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l= (2*i) +1, r =(2*i) +2;

    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i){
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    } 
}

void heap_sort(int arr[], int n){
    for(int i = (n/2)-1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int j = n-1; j > 0; j--){
        int t = arr[j];
        arr[j] = arr[0];
        arr[0] = t;
        heapify(arr, j, 0);
    }
}