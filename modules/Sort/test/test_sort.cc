#include "sort.h"
#include "gtest/gtest.h"

/**
 * @brief Test fixture for insertion sort with integer arrays.
 */
class InsertionSortWithInt : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>>
{
};

/**
 * @brief Tests the insertion sort algorithm with various integer arrays.
 */
TEST_P(InsertionSortWithInt, TestSortWithMultipleTypeInputs)
{
  std::vector<int> input = std::get<0>(GetParam());
  std::vector<int> expected = std::get<1>(GetParam());

  int *arr = input.data();
  size_t arr_size = input.size();

  Sort<int> s_obj;
  s_obj.InsertionSort(arr, arr_size);

  EXPECT_TRUE(std::equal(input.begin(), input.end(), expected.begin()));
}

INSTANTIATE_TEST_SUITE_P(
    SortTestInstance,
    InsertionSortWithInt,
    ::testing::Values(
        std::make_tuple(std::vector<int>{5, 4, 3, 2, 1}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_tuple(std::vector<int>{5, 1, 3, 2, 4}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_tuple(std::vector<int>{4, 1, 5, 2, 3}, std::vector<int>{1, 2, 3, 4, 5})));

/**
 * @brief Test fixture for insertion sort with double arrays.
 */
class InsertionSortWithDouble : public testing::TestWithParam<std::tuple<std::vector<double>, std::vector<double>>>
{
};

/**
 * @brief Tests the insertion sort algorithm with various double arrays.
 */
TEST_P(InsertionSortWithDouble, TestSortWithMultipleTypeInputs)
{
  std::vector<double> input = std::get<0>(GetParam());
  std::vector<double> expected = std::get<1>(GetParam());

  double *arr = input.data();
  size_t arr_size = input.size();

  Sort<double> s_obj;
  s_obj.InsertionSort(arr, arr_size);

  EXPECT_TRUE(std::equal(input.begin(), input.end(), expected.begin()));
}

INSTANTIATE_TEST_SUITE_P(
    SortTestInstance,
    InsertionSortWithDouble,
    ::testing::Values(
        std::make_tuple(std::vector<double>{5.1, 2.2, 9.9, 1.1, 5.5, 6.6}, std::vector<double>{1.1, 2.2, 5.1, 5.5, 6.6, 9.9}),
        std::make_tuple(std::vector<double>{3.3, 0.0, -1.1, 8.8, 7.7, 2.2}, std::vector<double>{-1.1, 0.0, 2.2, 3.3, 7.7, 8.8}),
        std::make_tuple(std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5}, std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5})));

/**
 * @brief Test fixture for selection sort with integer arrays.
 */
class SelectionSortWithInt : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>>
{
};

/**
 * @brief Tests the selection sort algorithm with various integer arrays.
 */
TEST_P(SelectionSortWithInt, TestSortWithMultipleTypeInputs)
{
  std::vector<int> input = std::get<0>(GetParam());
  std::vector<int> expected = std::get<1>(GetParam());

  int *arr = input.data();
  size_t arr_size = input.size();

  Sort<int> s_obj;
  s_obj.SelectionSort(arr, arr_size);

  EXPECT_TRUE(std::equal(input.begin(), input.end(), expected.begin()));
}

INSTANTIATE_TEST_SUITE_P(
    SortTestInstance,
    SelectionSortWithInt,
    ::testing::Values(
        std::make_tuple(std::vector<int>{5, 4, 3, 2, 1}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_tuple(std::vector<int>{5, 1, 3, 2, 4}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_tuple(std::vector<int>{4, 1, 5, 2, 3}, std::vector<int>{1, 2, 3, 4, 5})));

/**
 * @brief Test fixture for selection sort with double arrays.
 */
class SelectionSortWithDouble : public testing::TestWithParam<std::tuple<std::vector<double>, std::vector<double>>>
{
};

/**
 * @brief Tests the selection sort algorithm with various double arrays.
 */
TEST_P(SelectionSortWithDouble, TestSortWithMultipleTypeInputs)
{
  std::vector<double> input = std::get<0>(GetParam());
  std::vector<double> expected = std::get<1>(GetParam());

  double *arr = input.data();
  size_t arr_size = input.size();

  Sort<double> s_obj;
  s_obj.InsertionSort(arr, arr_size);

  EXPECT_TRUE(std::equal(input.begin(), input.end(), expected.begin()));
}

INSTANTIATE_TEST_SUITE_P(
    SortTestInstance,
    SelectionSortWithDouble,
    ::testing::Values(
        std::make_tuple(std::vector<double>{5.1, 2.2, 9.9, 1.1, 5.5, 6.6}, std::vector<double>{1.1, 2.2, 5.1, 5.5, 6.6, 9.9}),
        std::make_tuple(std::vector<double>{3.3, 0.0, -1.1, 8.8, 7.7, 2.2}, std::vector<double>{-1.1, 0.0, 2.2, 3.3, 7.7, 8.8}),
        std::make_tuple(std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5}, std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5})));
