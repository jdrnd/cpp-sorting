#include <cassert>
#include <cstdlib>
#include <iostream>

#include <benchmark/benchmark.h>

#include "SortingTests.h"

static void BM_countingSort(benchmark::State& state) {
    srand(time(0));
    size_t size = state.range(0);

    std::vector<int> arr(size);
    for (auto &v: arr) v = rand();

    assert(!std::is_sorted(arr.begin(), arr.end()));
    for (auto _ : state) {
        countingSort(arr);
    }
    assert(std::is_sorted(arr.begin(), arr.end()));
}
BENCHMARK(BM_countingSort)->Range(512, 512<<6)->Unit(benchmark::kMillisecond);

static void BM_bubbleSort(benchmark::State& state) {
    srand(time(0));
    size_t size = state.range(0);

    std::vector<int> arr(size);
    for (auto &v: arr) v = rand();

    assert(!std::is_sorted(arr.begin(), arr.end()));
    for (auto _ : state) {
        bubbleSort(arr);
    }
    assert(std::is_sorted(arr.begin(), arr.end()));
}
BENCHMARK(BM_bubbleSort)->Range(512, 512<<6)->Unit(benchmark::kMillisecond);

static void BM_selectionSort(benchmark::State& state) {
    srand(time(0));
    size_t size = state.range(0);

    std::vector<int> arr(size);
    for (auto &v: arr) v = rand();

    assert(!std::is_sorted(arr.begin(), arr.end()));
    for (auto _ : state) {
        selectionSort(arr);
    }
    assert(std::is_sorted(arr.begin(), arr.end()));
}
BENCHMARK(BM_selectionSort)->Range(512, 512<<6)->Unit(benchmark::kMillisecond);

static void BM_heapSort(benchmark::State& state) {
    srand(time(0));
    size_t size = state.range(0);

    std::vector<int> arr(size);
    for (auto &v : arr) { v = rand(); }

    assert(!std::is_sorted(arr.begin(), arr.end()));
    for (auto _ : state) {
        heapSort(arr);
    }
    assert(std::is_sorted(arr.begin(), arr.end()));
}
BENCHMARK(BM_heapSort)->Range(512, 512<<6)->Unit(benchmark::kMillisecond);


static void BM_mergeSort(benchmark::State& state) {
    srand(time(0));
    size_t size = state.range(0);

    std::vector<int> arr(size);
    for (auto &v: arr) v = rand();

    assert(!std::is_sorted(arr.begin(), arr.end()));
    for (auto _ : state) {
        mergeSort(arr);
    }
    assert(std::is_sorted(arr.begin(), arr.end()));
}
BENCHMARK(BM_mergeSort)->Range(512, 512<<6)->Unit(benchmark::kMillisecond);

static void BM_quickSort(benchmark::State& state) {
    srand(time(0));
    size_t size = state.range(0);

    std::vector<int> arr(size);
    for (auto &v: arr) v = rand();

    assert(!std::is_sorted(arr.begin(), arr.end()));
    for (auto _ : state) {
        quickSort(arr);
    }
    assert(std::is_sorted(arr.begin(), arr.end()));
}
BENCHMARK(BM_quickSort)->Range(512, 512<<6)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();