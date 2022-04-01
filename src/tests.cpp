#include "tests.h"
#include <cmath>
#include <iostream>

using namespace std;

void time_merge_sort(int *table, int idx_start, int idx_end) {
    clock_t start, finish; // zmienne do zliczania czasu
    double time = 0;
    start = clock(); // początek zliczania czasu

    merge_sort(table, idx_start, idx_end);

    finish = clock(); // koniec zliczania czasu
    time = (double)(finish - start) / (double)(CLOCKS_PER_SEC); // przeliczenie na sekundy
    cout << time << "s" << endl;
}

void time_quick_sort(int *table, int idx_start, int idx_end) {
    clock_t start, finish;
    double time=0;
    start = clock();

    quick_sort(table, idx_start, idx_end);

    finish = clock();
    time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
    cout << time << "s" << endl;
}

void time_heap_sort(int *table, int size) {
    clock_t start, finish;
    double time=0;
    start = clock();

    heap_sort(table, size);

    finish = clock();
    time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
    cout << time << "s" << endl;
}

void time_shell_sort(int *table, int size) {
    clock_t start, finish;
    double time=0;
    start = clock();

    shell_sort(table, size);

    finish = clock();
    time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
    cout << time << "s" << endl;
}

void print_test(int size) {
    int *tab = new int[size];
    int *tab1 = new int[size];
    int *tab2 = new int[size];
    int *tab3 = new int[size];

    table_create(tab, size);
    cout << "Created table: \n";
    table_print(tab, size);

    for (int i = 0; i < size; i++) {
        tab1[i] = tab[i];
        tab2[i] = tab[i];
        tab3[i] = tab[i];
    }

    merge_sort(tab, 0, size-1);
    cout << "Sorted table by mergesort: \n";
    table_print(tab, size);

    quick_sort(tab1, 0, size-1);
    cout << "Sorted table by quicksort: \n";
    table_print(tab1, size);

    heap_sort(tab2, size);
    cout << "Sorted table by heapsort: \n";
    table_print(tab2, size);

    shell_sort(tab3, size);
    cout << "Sorted table by shellsort: \n";
    table_print(tab3, size);

    delete [] tab;
    delete [] tab1;
    delete [] tab2;
    delete [] tab3;
}

void time_print_test(int size) {
    int *tab = new int[size];
    int *tab1 = new int[size];
    int *tab2 = new int[size];
    int *tab3 = new int[size];

    table_create(tab, size);
    cout << "Created table: \n";
    table_print(tab, size);

    for (int i = 0; i < size; i++) {
        tab1[i] = tab[i];
        tab2[i] = tab[i];
        tab3[i] = tab[i];
    }
    cout << "Operation time:";
    time_merge_sort(tab, 0, size-1);
    cout << "Sorted table by mergesort: \n";
    table_print(tab, size);

    cout << "Operation time:";
    time_quick_sort(tab1, 0, size-1);
    cout << "Sorted table by quicksort: \n";
    table_print(tab1, size);

    cout << "Operation time:";
    time_heap_sort(tab2, size);
    cout << "Sorted table by heapsort: \n";
    table_print(tab2, size);

    cout << "Operation time:";
    time_shell_sort(tab3, size);
    cout << "Sorted table by shellsort: \n";
    table_print(tab3, size);

    delete [] tab;
    delete [] tab1;
    delete [] tab2;
    delete [] tab3;
}

void random_time_test(int size) {
    int *tab = new int[size];
    int *tab1 = new int[size];
    int *tab2 = new int[size];
    int *tab3 = new int[size];

    table_create(tab, size);
//    cout << "Created table: \n";
//    table_print(tab, size);

    for (int i = 0; i < size; i++) {
        tab1[i] = tab[i];
        tab2[i] = tab[i];
        tab3[i] = tab[i];
    }
    cout << "Mergesort operation time for " << size << " elements: ";
    time_merge_sort(tab, 0, size-1);

    cout << "Quicksort operation time for " << size << " elements: ";
    time_quick_sort(tab1, 0, size-1);

    cout << "Quicksort operation time for " << size << " elements: ";
    time_heap_sort(tab2, size);

    cout << "Shellsort operation time for " << size << " elements: ";
    time_shell_sort(tab3, size);

    delete [] tab;
    delete [] tab1;
    delete [] tab2;
    delete [] tab3;
}

void sorted_test(int size, float percent) {
    int *tab = new int[size];
    int *tab1 = new int[size];
   // float percents = (float)percent;
    float x = (percent/100);
    //cout << endl << "x value is: " << x;
    int y = (int)(size*x);
    //cout << endl << "y value is: " << y;

    cout << "created tab:" << endl;
    table_create(tab,size);
    table_print(tab,size);

    for (int i = 0; i < size; i++) {
        tab1[i] = tab[i];
    }
    quick_sort(tab,0,size-1); // sortuje całą tablice

    cout << "sorted tab:" << endl;
    table_print(tab,size);

    for (int i = y; i < size; i++){
        tab[i] = tab1[i];
    }
    cout << "final tab" << endl;
    table_print(tab,size);
}

/////////////////////////////////////////////////////////////////////////////////////
/// Z WYPISANIEM GRAFICZNYM DLA LOSOWYCH
void random_time_merge_sort(int idx_start, int idx_end, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

    for (int i = 0; i < counter; i++) {

        int *table = new int[idx_end];
        table_create(table,idx_end);

        start = clock(); // poczatek zliczania czasu
        merge_sort(table, idx_start, idx_end);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;} // nadpisuje max
        if (time < min) { min = time;} // nadpisuje min
        //table_print(table,idx_end); wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    cout << "Mergesort for "<< counter << " tables with " << idx_end << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

void random_time_quick_sort(int idx_start, int idx_end, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

    for (int i = 0; i < counter; i++) {

        int *table = new int[idx_end];
        table_create(table,idx_end);

        start = clock(); // poczatek zliczania czasu
        quick_sort(table, idx_start, idx_end);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,idx_end); wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    cout << "Quicksort for "<< counter << " tables with " << idx_end << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

void random_time_heap_sort(int size, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_create(table,size);

        start = clock(); // poczatek zliczania czasu
        heap_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    cout << "Heapsort for "<< counter << " tables with " << size << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

void random_time_shell_sort(int size, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_create(table,size);

        start = clock(); // poczatek zliczania czasu
        shell_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    cout << "Shellsort for "<< counter << " tables with " << size << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////
/// Z WYPISANIEM GRAFICZNYM POSORTOWANYCH
void sorted_time_merge_sort(int idx_start, int idx_end, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

        for (int i = 0; i < counter; i++) {

            int *table = new int[idx_end];
            table_sorted_create(table,idx_end, percent);
            //table_print(table,idx_end);
            start = clock(); // poczatek zliczania czasu
            merge_sort(table, idx_start, idx_end);
            finish = clock(); // koniec zliczania czasu

            time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
            time_overal += time;

            if (time > max) { max = time;}
            if (time < min) { min = time;}
            //table_print(table,idx_end); //wizualnie przy malych liczbach ze dziala
            delete [] table;
        }
    avg = time_overal/counter;
    cout << "Mergesort for "<< counter << " tables already sorted in " << percent <<"%, with " << idx_end << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

void sorted_time_quick_sort(int idx_start, int idx_end, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

    for (int i = 0; i < counter; i++) {

        int *table = new int[idx_end];
        table_sorted_create(table,idx_end, percent);
        //table_print(table,idx_end);
        start = clock(); // poczatek zliczania czasu
        quick_sort(table, idx_start, idx_end);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,idx_end); //wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    cout << "Quicksort for "<< counter << " tables already sorted in " << percent <<"%, with " << idx_end << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

void sorted_time_heap_sort(int size, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_sorted_create(table, size, percent);
        //table_print(table,size);

        start = clock(); // poczatek zliczania czasu
        heap_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    cout << "Heapsort for "<< counter << " tables already sorted in " << percent <<"%, with " << size << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

void sorted_time_shell_sort(int size, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_sorted_create(table, size, percent);
        //table_print(table,size);

        start = clock(); // poczatek zliczania czasu
        shell_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    cout << "Shellsort for "<< counter << " tables already sorted in " << percent <<"%, with " << size << " elements" << endl;
    cout << "Overall time: " << time_overal << "s" << endl;
    cout << "Avg time: " << avg << "s" << endl;
    cout << "Min time: " << min << "s" << endl;
    cout << "Max time: " << max << "s" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////
/// Z WYPISANIEM DO TABLICY POSROTOWANYCH
void sorted_merge_sort(int idx_start, int idx_end, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[7];

    for (int i = 0; i < counter; i++) {

        int *table = new int[idx_end];
        table_sorted_create(table,idx_end, percent);
        //table_print(table,idx_end);
        start = clock(); // poczatek zliczania czasu
        merge_sort(table, idx_start, idx_end);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,idx_end); //wizualnie przy malych liczbach ze dziala
        delete [] table;
    }

    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = idx_end; // rozmiar
    k++;
    stat[k] = percent; // stopien posortowania
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,7);
}

void sorted_quick_sort(int idx_start, int idx_end, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[7];

    for (int i = 0; i < counter; i++) {

        int *table = new int[idx_end];
        table_sorted_create(table,idx_end, percent);
        //table_print(table,idx_end);
        start = clock(); // poczatek zliczania czasu
        quick_sort(table, idx_start, idx_end);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,idx_end); //wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = idx_end; // rozmiar
    k++;
    stat[k] = percent; // stopien posortowania
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,7);
}

void sorted_heap_sort(int size, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[7];

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_sorted_create(table, size, percent);
        //table_print(table,size);

        start = clock(); // poczatek zliczania czasu
        heap_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = size; // rozmiar
    k++;
    stat[k] = percent; // stopien posortowania
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,7);
}

void sorted_shell_sort(int size, int counter, float percent) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[7];

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_sorted_create(table, size, percent);
        //table_print(table,size);

        start = clock(); // poczatek zliczania czasu
        shell_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = size; // rozmiar
    k++;
    stat[k] = percent; // stopien posortowania
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,7);
}

/////////////////////////////////////////////////////////////////////////////////////
/// Z WYPISANIEM DO TABLICY POSRTOWANYCH W ODWROTNEJ KOLEJNOSCI
void reversed_merge_sort(int idx_start, int idx_end, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[7];

    for (int i = 0; i < counter; i++) {

        int *table = new int[idx_end];
        table_create(table,idx_end);
        merge_sort(table, idx_start, idx_end);
        table_reverse(table, idx_end);

        start = clock(); // poczatek zliczania czasu
        merge_sort(table, idx_start, idx_end);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,idx_end); wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = idx_end; // rozmiar
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,6);
}

void reversed_quick_sort(int idx_start, int idx_end, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[6];

    for (int i = 0; i < counter; i++) {

        int *table = new int[idx_end];
        table_create(table,idx_end);
        quick_sort(table, idx_start, idx_end);
        table_reverse(table, idx_end);

        start = clock(); // poczatek zliczania czasu
        quick_sort(table, idx_start, idx_end);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,idx_end); wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = idx_end; // rozmiar
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,6);
}

void reversed_heap_sort(int size, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[6];

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_create(table,size);
        heap_sort(table, size);
        table_reverse(table, size);

        start = clock(); // poczatek zliczania czasu
        heap_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = size; // rozmiar
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,6);
}

void reversed_shell_sort(int size, int counter) {
    clock_t start, finish;
    double time = 0;
    double time_overal = 0;
    double min = 999999;
    double max = 0;
    double avg = 0;
    int k = 0;
    float *stat = new float[6];

    for (int i = 0; i < counter; i++) {

        int *table = new int[size];
        table_create(table,size);
        heap_sort(table, size);
        table_reverse(table, size);

        start = clock(); // poczatek zliczania czasu
        shell_sort(table, size);
        finish = clock(); // koniec zliczania czasu

        time = (double)(finish - start) / (double)(CLOCKS_PER_SEC);
        time_overal += time;

        if (time > max) { max = time;}
        if (time < min) { min = time;}
        //table_print(table,size); // wizualnie przy malych liczbach ze dziala
        delete [] table;
    }
    avg = time_overal/counter;
    stat[k] = counter; // ilosc tablic
    k++;
    stat[k] = size; // rozmiar
    k++;
    stat[k] = avg; // srednia wartosc
    k++;
    stat[k] = min; // najkrótszy czas
    k++;
    stat[k] = max; // najdłuższy czas
    k++;
    stat[k] = time_overal; // cały czas
    table_print2(stat,6);
}

/////////////////////////////////////////////////////////////////////////////////////

void stat_random_print() {
    cout << "start" << endl;
    random_time_merge_sort(0, 10000, 100);
    random_time_merge_sort(0, 50000, 100);
    random_time_merge_sort(0, 100000, 100);
    random_time_merge_sort(0, 500000, 100);
    random_time_merge_sort(0, 1000000, 100);
    cout << "------------------------------------------------------" << endl;
    random_time_quick_sort(0, 10000, 100);
    random_time_quick_sort(0, 50000, 100);
    random_time_quick_sort(0, 100000, 100);
    random_time_quick_sort(0, 500000, 100);
    random_time_quick_sort(0, 1000000, 100);
    cout << "------------------------------------------------------" << endl;
//    random_time_heap_sort(10, 10);
    random_time_heap_sort(10000, 100);
    random_time_heap_sort(50000, 100);
    random_time_heap_sort(100000, 100);
    random_time_heap_sort(500000, 100);
    random_time_heap_sort(1000000, 100);
    cout << "------------------------------------------------------" << endl;
//    random_time_shell_sort(10, 10);
    random_time_shell_sort(10000, 100);
    random_time_shell_sort(50000, 100);
    random_time_shell_sort(100000, 100);
    random_time_shell_sort(500000, 100);
    random_time_shell_sort(1000000, 100);
    cout << "end" << endl;
}

void stat_sorted_print() {
    float percent[6] = {25, 50, 75, 95, 99, 99.7};

    cout << "MERGESORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        sorted_time_merge_sort(0, 10000, 100, percent[j]);
        sorted_time_merge_sort(0, 50000, 100, percent[j]);
        sorted_time_merge_sort(0, 100000, 100, percent[j]);
        sorted_time_merge_sort(0, 500000, 100, percent[j]);
        sorted_time_merge_sort(0, 1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
    cout << "QUICKSORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        sorted_time_quick_sort(0, 10000, 100, percent[j]);
        sorted_time_quick_sort(0, 50000, 100, percent[j]);
        sorted_time_quick_sort(0, 100000, 100, percent[j]);
        sorted_time_quick_sort(0, 500000, 100, percent[j]);
        sorted_time_quick_sort(0, 1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
    cout << "HEAPSORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        sorted_time_heap_sort(10000, 100, percent[j]);
        sorted_time_heap_sort(50000, 100, percent[j]);
        sorted_time_heap_sort(100000, 100, percent[j]);
        sorted_time_heap_sort(500000, 100, percent[j]);
        sorted_time_heap_sort(1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
    cout << "SHELLSORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        sorted_time_shell_sort(10000, 100, percent[j]);
        sorted_time_shell_sort(50000, 100, percent[j]);
        sorted_time_shell_sort(100000, 100, percent[j]);
        sorted_time_shell_sort(500000, 100, percent[j]);
        sorted_time_shell_sort(1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
}

void stat_sorted() {
    float percent[6] = {25, 50, 75, 95, 99, 99.7};

    cout << "MERGESORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "tabs size %     avg      min       max     time" << endl;
        sorted_merge_sort(0, 10000, 100, percent[j]);
        sorted_merge_sort(0, 50000, 100, percent[j]);
        sorted_merge_sort(0, 100000, 100, percent[j]);
        sorted_merge_sort(0, 500000, 100, percent[j]);
        sorted_merge_sort(0, 1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
    cout << "QUICKSORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "tabs size %     avg      min       max     time" << endl;
        sorted_quick_sort(0, 10000, 100, percent[j]);
        sorted_quick_sort(0, 50000, 100, percent[j]);
        sorted_quick_sort(0, 100000, 100, percent[j]);
        sorted_quick_sort(0, 500000, 100, percent[j]);
        sorted_quick_sort(0, 1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
    cout << "HEAPSORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "tabs size %     avg      min       max     time" << endl;
        sorted_heap_sort(10000, 100, percent[j]);
        sorted_heap_sort(50000, 100, percent[j]);
        sorted_heap_sort(100000, 100, percent[j]);
        sorted_heap_sort(500000, 100, percent[j]);
        sorted_heap_sort(1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
    cout << "SHELLSORT" << endl;
    for (int j = 0; j < 6; j++) {
        cout << "---------------------------------------------------" << endl;
        cout << "ALREADY SORTED IN " << percent[j] << "%" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "tabs size %     avg      min       max     time" << endl;
        sorted_shell_sort(10000, 100, percent[j]);
        sorted_shell_sort(50000, 100, percent[j]);
        sorted_shell_sort(100000, 100, percent[j]);
        sorted_shell_sort(500000, 100, percent[j]);
        sorted_shell_sort(1000000, 100, percent[j]);

        cout << "---------------------------------------------------" << endl;
        if (j == 5) { cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------" << endl;}
    }
}

void stat_reversed() {
    cout << "MERGESORT REVERSE SORTED" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "tabs size    avg      min       max     time" << endl;
    reversed_merge_sort(0,10000,100);
    reversed_merge_sort(0, 50000, 100);
    reversed_merge_sort(0, 100000, 100);
    reversed_merge_sort(0, 500000, 100);
    reversed_merge_sort(0, 1000000, 100);
    cout << "---------------------------------------------------" << endl;

    cout << "QUICKSORT REVERSE SORTED" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "tabs size    avg      min       max     time" << endl;
    reversed_quick_sort(0,10000,100);
    reversed_quick_sort(0, 50000, 100);
    reversed_quick_sort(0, 100000, 100);
    reversed_quick_sort(0, 500000, 100);
    reversed_quick_sort(0, 1000000, 100);
    cout << "---------------------------------------------------" << endl;

    cout << "HEAPSORT REVERSE SORTED" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "tabs size    avg      min       max     time" << endl;
    reversed_heap_sort(10000, 100);
    reversed_heap_sort(50000, 100);
    reversed_heap_sort(100000, 100);
    reversed_heap_sort(500000, 100);
    reversed_heap_sort(1000000, 100);
    cout << "---------------------------------------------------" << endl;


    cout << "SHELLSORT REVERSE SORTED" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "tabs size    avg      min       max     time" << endl;
    reversed_shell_sort(10000, 100);
    reversed_shell_sort(50000, 100);
    reversed_shell_sort(100000, 100);
    reversed_shell_sort(500000, 100);
    reversed_shell_sort(1000000, 100);
    cout << "---------------------------------------------------" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////

