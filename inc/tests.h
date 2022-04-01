#ifndef PAMSI_PROJEKT1_TESTS_H
#define PAMSI_PROJEKT1_TESTS_H
#include "functions.hh"

/// ZE ZLICZANIEM CZASU JEDNEGO PRZEBIEGU
void time_merge_sort(int *table, int idx_start, int idx_end);
void time_quick_sort(int *table, int idx_start, int idx_end);
void time_heap_sort(int *table, int size);
void time_shell_sort(int *table, int size);

/// FUNKCJE POMOCNICZE
void print_test(int size);
void time_print_test(int size);
void random_time_test(int size);
void sorted_test(int size, float percent);

/// FUNKCJE DO TESTOW
void random_time_merge_sort(int idx_start, int idx_end, int counter); // dla counter tablic statystyki
void random_time_quick_sort(int idx_start, int idx_end, int counter); // dla counter tablic statystyki
void random_time_heap_sort(int size, int counter);
void random_time_shell_sort(int size, int counter);

void sorted_time_merge_sort(int idx_start, int idx_end, int counter, float percent);
void sorted_time_quick_sort(int idx_start, int idx_end, int counter, float percent);
void sorted_time_heap_sort(int size, int counter, float percent);
void sorted_time_shell_sort(int size, int counter, float percent);

void sorted_merge_sort(int idx_start, int idx_end, int counter, float percent);
void sorted_quick_sort(int idx_start, int idx_end, int counter, float percent);
void sorted_heap_sort(int size, int counter, float percent);
void sorted_shell_sort(int size, int counter, float percent);

void reversed_merge_sort(int idx_start, int idx_end, int counter);
void reversed_quick_sort(int idx_start, int idx_end, int counter);
void reversed_heap_sort(int size, int counter);
void reversed_shell_sort(int size, int counter);

/// STATYSTYKI
void stat_random_print();
void stat_sorted_print();
void stat_sorted();
void stat_reversed();

#endif
