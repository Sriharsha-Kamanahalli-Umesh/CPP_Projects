#include "sort.h"

/**
 * @brief Sorts an array using the insertion sort algorithm.
 * 
 * @tparam T The type of the elements in the array.
 * @param arr The array to be sorted.
 * @param arr_size The size of the array.
 */
template <typename T>
void Sort<T>::InsertionSort(T arr[], size_t const arr_size)
{
  for (size_t index = 0; index < arr_size; index++)
  {
    size_t next_index = index;
    while (next_index > 0 && arr[next_index - 1] > arr[next_index])
    {
      T temp_val = arr[next_index - 1];
      arr[next_index - 1] = arr[next_index];
      arr[next_index] = temp_val;
      next_index--;
    }
  }
}

/**
 * @brief Sorts an array using the selection sort algorithm.
 * 
 * @tparam T The type of the elements in the array.
 * @param arr The array to be sorted.
 * @param arr_size The size of the array.
 */
template <typename T>
void Sort<T>::SelectionSort(T arr[], size_t const arr_size)
{
  for (size_t index = 0; index < arr_size; index++)
  {
    size_t min_pos = index;
    for (size_t next_index = index + 1; next_index < arr_size; next_index++)
    {
      if (arr[next_index] < arr[min_pos])
      {
        min_pos = next_index;
      }
    }
    T temp_val = arr[min_pos];
    arr[min_pos] = arr[index];
    arr[index] = temp_val;
  }
}

template class Sort<int>;
template class Sort<double>;
// template class Sort<std::string>;