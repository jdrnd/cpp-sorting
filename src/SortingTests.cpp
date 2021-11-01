#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
#include <array>
#include <stdio.h>
#include <map>
#include <climits>
#include <chrono>
#include <cstring>
#include <cmath>
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

  // Parititon
  int pivotIndex = floor((left + right) / 2);  // Using left-most element as pivot makes it n^2
  int pivotVal = val[pivotIndex];

  int i = left;  // left index
  int j = right;  // right index

  int temp;
  while (true) {
    while (val[i] < pivotVal && i < right) i++;
    while (val[j] > pivotVal && j > left) j--;

    if (i >= j) {
      pivotIndex = j;
      break;
    } else {
      // swap
      temp = val[i];
      val[i] = val[j];
      val[j] = temp;
    }
  }

  // recurse
  quickSortRecursive(val, left, pivotIndex);
  quickSortRecursive(val, pivotIndex + 1, right);
}


void quickSort(std::vector<int>& val) {
    quickSortRecursive(val, 0, val.size() - 1);
}

void countingSort(std::vector<int>& val) {
  std::map<int, uint> counts;

  for (const auto& value : val) {
    if (counts.count(value) == 0) { counts[value] = 1; } 
    else {
      counts[value]++;
    }
  }

  uint position = 0;
  for (const auto& pair : counts) {
    uint count = pair.second;
    for (int i = 0; i < count; i++) {
      val[position] = pair.first;
      position++;
    }
  }

  // uint position = 0;
  // for (uint bucket = 0; bucket < UINT_MAX; bucket++) {
  //   if (counts[bucket] == 0) {
  //     continue;
  //   } else {
  //     uint repeat = counts[bucket];
  //     for (uint i = 0; i < repeat; i++) {
  //       val[position] = (int) bucket;
  //       position++;
  //     }
  //   }
  // }
  // delete counts;
}


