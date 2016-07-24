#ifndef C_SORTING_SORTINGTESTS_H
#define C_SORTING_SORTINGTESTS_H


#include <iostream>


class SortingTest{

    int* values;
    int size;

    void initialize();

    void quickSort(int* val, int size);
    void selectionSort(int* val, int size);
    void mergeSort(int* val, int size);
    void heapSort(int* val, int size);
    void quickSort(int* val, int size);

    public:
        void runTest();

};










#endif //C_SORTING_SORTINGTESTS_H
