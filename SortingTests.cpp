#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <queue>

#include "SortingTests.h"



bool SortingTest::initialize(){

    int vals = 0;
    values = new int*[5];
    do {
        std::cout << "\n Enter number of values to test sorting with: ";

        std::cin >> vals;

        if (vals <= 0 || vals > 65535){
            std::cout << "\n Please enter a valid size";
        }
    }while (vals <= 0 || vals > 65535);

    // Initialize test arrays
    size = vals;
    for (int i = 0; i<5; i++){
        values[i] = new int[vals];
    }

    srand((unsigned)time(0));
    int randi;

    // Fill arrays with values
    for (int i = 0; i<size; i++){
        randi = rand();

        for (int j = 0; j<5; j++){
            values[j][i] = (unsigned)randi;
        }
    }
}

void SortingTest::bubbleSort(int *val) {

    int temp;
    bool swapped = true;

    while (swapped){
        swapped = false;

        for (int i = 0; i < size; i++){

            if (val[i] > val[i+1]){
                temp = val[i];
                val[i] = val[i+1];
                val[i+1] = temp;
                swapped = true;
            }
        }
    }
}

void SortingTest::selectionSort(int *val) {

    int min = 0;
    int temp;

    for (int i = 0; i<size; i++){
        min = i;
        for (int j = i; j<size; j++){
            if (val[j] < val[min]){
                min = j;
            }
        }

        if (min != i){
            temp = val[i];
            val[i] = val[min];
            val[min] = temp;
        }
    }
}

void SortingTest::mergeSort(int* val){
    mergeSortRecursive(val, 0, size-1);
}

void  SortingTest::mergeSortRecursive(int* val, int left, int right) {
    if (left < 0 || right < 0);
    if (left >= right) return;

    // If size is 2
    if (right == left + 1){
        if (val[left] > val[right]){
            int temp = val[left];
            val[left] = val[right];
            val[right] = temp;
        }

    }

    int half = left + (right - left) / 2;

    mergeSortRecursive(val, left, half);
    mergeSortRecursive(val, half + 1, right);

    int merge[right-left +1];

    int r = half+1;
    int l = left;

    int temppos = 0;

    while (l <= half && r <= right){

        // Add smallest leading value to temp, increment leading value;
        if (val[l] > val[r]){
            merge[temppos] = val[r];
            r++;
        }
        else{
            merge[temppos] = val[l];
            l++;
        }
        temppos++;


        // If one side finished itterate through other side
        if (l > half){
            for (; r<= right; r++, temppos++){
                merge[temppos] = val[r];
            }
            break;
        }
        if (r > right){
            for(; l <= half; l++, temppos++){
                merge[temppos] = val[l];
            }
            break;
        }
    }

    // Copy temp array back to main
    for (int i = 0; i < right - left +1; i++){
        val[left + i] = merge[i];
    }
}

void SortingTest::heapSort(int *val) {

    std::priority_queue<int> queue;

    // Comprise a max heap/priority queue
    for (int i=0; i<size; i++){
        queue.push(val[i]);
    }

    // Reverse order using a stack
    std::stack<int> stack;
    int temp;
    for (int i = 0; i<size; i++){
        temp = queue.top();
        queue.pop();
        stack.push(temp);
    }

    for (int i=0; i<size; i++){
        val[i] = stack.top();
        stack.pop();
    }
}

void SortingTest::quickSort(int *val){
    quickSortRecursive(val, 0, size - 1);
}


void SortingTest::quickSortRecursive(int *val, int left, int right) {

  if (left >= right) return;
  if (left < 0 || right < 0) return;

  int pivotIndex = left;

  int x,y;

  x = left + 1;
  y = right;

  int temp;
  while(true){

    while(val[x] <= val[pivotIndex] && x <= right ) x++;
    if (x >= y ) break;

    while(val[y] >= val[pivotIndex] && y > x) y--;
    if (x >= y ) break;


    else{
      //swap
      temp = val[x];
      val[x] = val[y];
      val[y] = temp;
    }

  }

  // swap pivot and position
  if (pivotIndex != x - 1){
    temp = val[pivotIndex];
    val[pivotIndex] = val[x-1];
    val[x-1] = temp;

    pivotIndex = x - 1;
}


  // recurse
  quickSortRecursive(val, left, pivotIndex - 1);
  quickSortRecursive(val, pivotIndex + 1, right);

}



void SortingTest::runTest(){

    initialize();

    std::cout << "Running Bubblesort \n";
    print(0);
    std::cout << "\n";
    bubbleSort(values[0]);
    print(0);
    std::cout << "\n\n";

    std::cout << "Running Selectionsort \n";
    print(1);
    std::cout << "\n";
    selectionSort(values[1]);
    print(1);
    std::cout << "\n\n";

    std::cout << "Running Mergesort \n";
    print(2);
    std::cout << "\n";
    mergeSort(values[2]);
    print(2);
    std::cout << "\n\n";

    std::cout << "Running Heapsort \n";
    print(3);
    std::cout << "\n";
    heapSort(values[3]);
    print(3);
    std::cout << "\n\n";

    std::cout << "Running Quicksort \n";
    print(4);
    std::cout << "\n";
    quickSort(values[4]);
    print(4);
    std::cout << "\n\n";
}
void SortingTest::print(int i){
    for (int j = 0; j<20; j++){
        if (j<size) {
            std::cout << values[i][j] << " ";
        }
    }
}