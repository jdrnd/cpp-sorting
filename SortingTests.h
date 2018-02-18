#ifndef CPP_SORTING_SORTINGTESTS_H
#define CPP_SORTING_SORTINGTESTS_H

#include <iostream>

class SortingTest{
    int** values;
    int size;

    bool initialize();

    // Sort val array in place, size is known via instance varaible
    void bubbleSort(int* val);
    void selectionSort(int* val);
    void mergeSort(int* val);
    void heapSort(int* val);
    void quickSort(int* val);

    void mergeSortRecursive(int* val, int left, int right);
    void quickSortRecursive(int* val, int left, int right);

public:
        void runTest();
        // prints the first 20 elements of the ith array
        void print_first20(int i);

        ~SortingTest();
};
#endif //CPP_SORTING_SORTINGTESTS_H
