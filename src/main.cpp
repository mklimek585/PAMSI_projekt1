#include <iostream>
#include "functions.hh"
#include "tests.h"
#include <array>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
//    fstream fout;
//    fout.open("/sortowanie.txt, ios::out");
//    fout << "sdasdas" << endl;
    srand(time(NULL)); // by liczby były losowe
//fout << "drugi raz";
//    fout.close();
//    sorted_test(16, 25);
//    sorted_test(16, 50);
//    sorted_test(16, 75);
//    sorted_test(16, 95);
//    sorted_test(16, 99);
//    sorted_test(16, 99.7);

    int size = 20;
//    int tab[size];
//    table_create(tab, size);
//    quick_sort(tab, 0, size-1);
//    table_print(tab, size);
//    table_reverse(tab, size);
//    table_print(tab, size);

//stat_reversed();
//stat_random_print();
stat_sorted();

    return 0;
}