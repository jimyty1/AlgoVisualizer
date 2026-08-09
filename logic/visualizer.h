#ifndef VISUALIZER_H
#define VISUALIZER_H

void log_swap(int arr[], int n, int i, int j);
void log_compare(int arr[], int n, int i, int j);
void log_compare_value(int arr[], int n, int i, int value);
void log_partition(int arr[], int n, int start, int end, int pivot, int boundary, int j);
void log_merge_compare(int arr[], int n, int left, int right, int start, int mid, int end);
void log_merge_start(int arr[], int n, int start, int mid, int end);
void log_pivot_placed(int arr[], int n, int pivot);
void log_overwrite(int arr[], int n, int i, int j);
void log_pivotB(int arr[], int n, int pivot, int boundary, int j);
void log_heapify(int arr[], int n, int i, int largest);

#endif