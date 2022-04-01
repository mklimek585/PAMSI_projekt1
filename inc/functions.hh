#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/// FUNKCJE PODSTAWOWE

void table_create(int *table, int size);
void table_sorted_create(int *table, int size, float percent);
void table_reverse(int *table, int size);
void table_print(int *table, int size);
void table_print2(float *table,int size);

/// FUNKCJE SORTUJACE
void merge(int *table, int idx_start, int idx_middle, int idx_end);
void merge_sort(int *table, int idx_start, int idx_end);
void quick_sort(int *table, int idx_start, int idx_end);
void heapify (int *table, int size, int i);
void heap_build(int *table, int size);
void heap_sort(int *table, int size);
void shell_sort(int *table, int size);



#endif