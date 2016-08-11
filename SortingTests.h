#ifndef C_SORTING_SORTINGTESTS_H
#define C_SORTING_SORTINGTESTS_H


#include <iostream>


class SortingTest{

    int** values;
    int size;

    bool initialize();

    void bubbleSort(int* val);
    void selectionSort(int* val);
    void mergeSort(int* val);
    void heapSort(int* val);
    void quickSort(int* val);


    void mergeSortRecursive(int* val, int left, int right);
    void quickSortRecursive(int* val, int left, int right);




    public:
        void runTest();

        // helper functions
        void print(int i);


        ~SortingTest();

};










#endif //C_SORTING_SORTINGTESTS_H
