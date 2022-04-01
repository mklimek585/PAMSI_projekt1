#include "functions.hh"
#include <cmath>
#include <iostream>

using namespace std;

void table_create(int *table, int size) {
    for (int i = 0; i < size; i++) {
        int nums = rand() % 10;
        table[i] = nums;
    }
}

void table_sorted_create(int *table, int size, float percent) {
    int *tab1 = new int[size];

// float percents = (float)percent;
    float x = (percent / 100);
//cout << endl << "x value is: " << x;
    int y = (int) (size * x);
//cout << endl << "y value is: " << y;

    table_create(table, size);
    for (int i = 0; i < size; i++) {
        tab1[i] = table[i];
    }
    quick_sort(table, 0, size - 1); // sortuje całą tablice

    for (int i = y; i < size; i++) {
        table[i] = tab1[i];
    }
    delete [] tab1;
}

void table_reverse(int *table, int size) {
    int *tab = new int[size];
    int j = size-1;
    for (int i = 0; i < size; i++) { // petla wypelniajaca tablice pomocnicza w odwrotnej kolejnosci
        tab[j] = table[i];
        j--;
    }
    for (int i = 0; i <= size; ++i) { // petla wypelniajaca glowna tablice
        table[i] = tab[i];
    }
}

void table_print(int *table,int size) {
    for (int i = 0; i < size; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
}

void table_print2(float *table,int size) {
    for (int i = 0; i < size; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
}

void merge(int *table, int idx_start, int idx_middle, int idx_end) {

    int n1 = idx_middle - idx_start + 1; // ustalam ilość elementów pierwszej połowy tablicy
    int n2 = idx_end - idx_middle; // ustalam ilość elementów drugiej połowy tablicy
    int *L = new int[n1];
    int *P = new int[n2]; // iniciuje dwie tablice o rozmiarach jak wyżej

    for (int i = 0; i < n1; i++)
        L[i] = table[idx_start + i]; // zapełniam tablice pierwszą połową wyrazów z tablicy początkowej
    for (int j = 0; j < n2; j++)
        P[j] = table[idx_middle + 1 + j]; // zapełniam tablice drugą połową wyrazów z tablicy początkowej

    int i1, i2, i3;
    i1 = 0; // index tablicy L
    i2 = 0; // index tablicy P
    i3 = idx_start; // index tablicy scalonej

    while (i1 < n1 && i2 < n2) { // gdy oba argumenty są prawdziwe
        if (L[i1] <= P[i2]) { // jeśli element "lewej" tablicy jest mniejszy badz rowny elementowi prawej
            table[i3] = L[i1]; // przypisuje go do tablicy scalonej
            i1++; // przechodze do nastepnego elementu TEJ SAMEJ tablicy
        } else {
            table[i3] = P[i2]; // jesli elementy w lewej sa juz wieksze - do tablicy scalonej wchodzi element z tablicy "prawej"
            i2++; // przesuniecie na nastepny element w porównaniu
        }
        i3++; // przesuniecie co wykonanie petli o 1 w tablicy z elementami scalonymi
    }

    while (i1 < n1) { // jeśli w tablicy lewej zostały jeszcze jakieś elementy to je przenosimy
        table[i3] = L[i1];
        i1++;
        i3++;
    }
    while (i2 < n2) { // jeśli w tablicy prawej zostały jeszcze jakieś elementy to je przenosimy
        table[i3] = P[i2];
        i2++;
        i3++;
    }
    delete[] L;  //---- w wersji z wskaźnikami
    delete[] P;  //---- w wersji z wskaźnikami
}

void merge_sort(int *table, int idx_start, int idx_end) {
    if (idx_start < idx_end) {
        int idx_middle = idx_start + (idx_end - idx_start) / 2; // index podzielenia tablicy na dwie

        merge_sort(table, idx_start, idx_middle); // rekurencyjnie dziele lewa czesc do 1 elementu
        merge_sort(table, idx_middle + 1, idx_end); // rekurencyjnie dziele prawa czesc do 1 elementu

        merge(table, idx_start, idx_middle, idx_end); // scalam te czesci w mniejsze az do rozmiaru tablicy startowej
    }
}

void quick_sort(int *table, int idx_start, int idx_end)
{
    if(idx_end <= idx_start) return;

    int i = idx_start - 1; // index pomocniczy idacy od lewej strony
    int j = idx_end + 1; // index pomocniczy idacy od prawej strony
    int pivot = table[(idx_start + idx_end)/2]; //wybieramy punkt odniesienia

    while(1)
    {
        while(pivot > table[++i]); // idąc od lewej strony tabeli do prawej szukam elementu wiekszego od ustalonego pivota
        while(pivot < table[--j]); // idąc od prawej strony tabeli do lewej szukam elementu mniejszego od ustalonego pivota

        if( i <= j) // sprawdzam czy liczniki sie minely, jesli nie to zamieniam elementy
            swap(table[i],table[j]); // z biblioteki std, zamiernia wartosciami tab[i] z tab[j]
        else
            break; // konczy petle gdy operatory indeksujace sie miną
    }
    // gdy operatory indeksujace sie miną wykonujemy oddzielne sortowanie dla lewej i prawej czesci
    if(j > idx_start)                            // rekurencja do quick_sort, sortowanie lewej czesci
        quick_sort(table, idx_start, j); // tablicy(ktorej juz elementy sa mniejsze niz prawej)
    if(i < idx_end)                              // rekurencja do quick_sort, sortowanie prawej czesci
        quick_sort(table, i, idx_end);  // tablicy(ktorej juz elementy sa wieksze niz lewej)
}

void heapify (int *table, int size, int i) {
    int temp_i = i, r = (i * 2) + 2, l = (i * 2) + 1; // zmienne pomocnicze

    if((l < size) && (table[i] < table[l])) temp_i = l; // sprawdza czy relacje z lewym
    if((r < size) && (table[temp_i] < table[r])) temp_i = r; // sprawdza relacje z prawym

    if(i != temp_i){ // gdy chociaż jedna realcja była źle
        int temp = table[i]; // przypisuje element do zmiennej pomocnicznej
        table[i] = table[temp_i]; // zamiana elementów
        table[temp_i] = temp; // przypisany element nadpisuje na drugi z zamiany

        heapify(table,size,temp_i); // wywołanie funkcji w indeksie zmiany
    }
}

void heap_build(int *table, int size) { // funkcja budujaca kopiec
    for(int i = (size - 2)/2; i >= 0; i--) { // budowanie kopca od punktu startowego
        heapify(table, size, i);
    }
}

void heap_sort(int *table, int size) {
    int i, temp; // zmienne pomocnicze
    heap_build(table,size); // budowanie pierwszego kopca

    for(i = size - 1 ; i > 0; i--) {   // pętla do wykluczania elementów posortowanych
        temp = table[i];     //
        table[i] = table[0]; // zamiana z ostatnim elementem w kopcu
        table[0] = temp;     //

        heapify(table,i,0); // przywrócenie własności kopca w punkcie
        temp = 0; // zeruje zmienna pomocnicza
    }
}

void shell_sort(int *table, int size) {
    int space = size / 2; // odestep do podziału tablic
    int temp = 0; // zmienna pomocnicza
    int j = 0; // zmienna pomocnicza
    while(space >= 1) { // aż tablice nie beda jednoelementowe
        for (int i = space; i < size; i++) {
            temp = table[i]; // obierany jest element tablicy na ktorym konczyla sie ostatnia operacja
            for (j = i; j >= space && table[j - space] > temp; j -= space) //inx wiekszy od przerwy i gdy element tablicy wiekszy od przyrownywanego
                table[j] = table[j - space];
            table[j] = temp; // zamiana elementów
        }
        space /= 2;
    }
}

