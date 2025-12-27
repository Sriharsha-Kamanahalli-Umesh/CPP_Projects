#include <iostream>

/**
 * @brief A class that provides various sorting algorithms.
 * 
 * @tparam T The type of the elements to be sorted.
 */
template <typename T>
class Sort
{
public:
  /**
   * @brief Sorts an array using the insertion sort algorithm.
   * 
   * @param arr The array to be sorted.
   * @param arr_size The size of the array.
   */
  void InsertionSort(T arr[], size_t const arr_size);

  /**
   * @brief Sorts an array using the selection sort algorithm.
   * 
   * @param arr The array to be sorted.
   * @param arr_size The size of the array.
   */
  void SelectionSort(T arr[], size_t const arr_size);

  /**
   * @brief Sorts an array using the bubble sort algorithm.
   * 
   * @param arr The array to be sorted.
   * @param arr_size The size of the array.
   */
  void BubleSort(T &arr, T const arr_size);

  /**
   * @brief Sorts an array using the merge sort algorithm.
   * 
   * @param arr The array to be sorted.
   * @param arr_size The size of the array.
   */
  void MergeSort(T &arr, T const arr_size);

  /**
   * @brief Sorts an array using the quick sort algorithm.
   * 
   * @param arr The array to be sorted.
   * @param arr_size The size of the array.
   */
  void QuickSort(T &arr, T const arr_size);
};