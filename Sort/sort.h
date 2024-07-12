#include <iostream>

template <typename T>
class Sort {
  public:
    void InsertionSort(T arr[], size_t const arr_size);
    void SelectionSort(T arr[], size_t const arr_size);
    void BubleSort(T& arr, T const arr_size);
    void MergeSort(T& arr, T const arr_size);
    void QuickSort(T& arr, T const arr_size);

};