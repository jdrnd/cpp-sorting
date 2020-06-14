#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include <chrono>
#include <cstdint>
#include <vector>

#include "SortingTests.h"

void bubbleSort(std::vector<int>& arr) {
    int temp;
    bool swapped = true;

    while (swapped){
        swapped = false;

        for (int i = 0; i < arr.size()-1; i++){

            if (arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
    }
}

void selectionSort(std::vector<int>& val) {
    int min = 0;
    int temp;

    for (int i = 0; i<val.size(); i++){
        min = i;
        for (int j = i; j<val.size(); j++){
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
    return;
}

void heapSort(std::vector<int>& val) {
    std::priority_queue<int> queue;

    // Comprise a max heap/priority queue
    for (int i=0; i<val.size(); i++){
        queue.push(val[i]);
    }

    // Reverse order using a stack
    std::stack<int> stack;
    int temp;
    for (int i = 0; i<val.size(); i++){
        temp = queue.top();
        queue.pop();
        stack.push(temp);
    }

    for (int i=0; i<val.size(); i++){
        val[i] = stack.top();
        stack.pop();
    }
}

void mergeSortRecursive(std::vector<int>& val, int left, int right) {
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

void mergeSort(std::vector<int>& val){
    mergeSortRecursive(val, 0, val.size()-1);
}

void quickSortRecursive(std::vector<int>& val, int left, int right) {

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


void quickSort(std::vector<int>& val){
    quickSortRecursive(val, 0, val.size() - 1);
}


