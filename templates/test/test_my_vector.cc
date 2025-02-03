#include "my_vector.h"
#include "gtest/gtest.h"

/**
 * @brief Test fixture for Myvector tests.
 */
class VectorFixture : public testing::Test
{
protected:
  Myvector<int> vec_obj = {10, 20, 30, 40, 50, 60};
  const Myvector<int> obj_vec = {10, 20, 30, 40};

  Myvector<std::string> vec = {"hello", "sriharsha", "how", "are", "you"};
};

/**
 * @brief Test to check vector initialization and push_back functionality.
 */
TEST_F(VectorFixture, VectorInitialization)
{
  vec_obj.push_back(70);
  vec_obj.push_back(80);

  Myvector<int> test_vec_obj;
  for (std::size_t i = 0; i < vec_obj.getSize(); i++)
  {
    test_vec_obj.push_back(vec_obj[i]);
  }
  for (std::size_t i = 0; i < vec_obj.getSize(); i++)
  {
    EXPECT_EQ(vec_obj[i], test_vec_obj[i]);
  }
}

/**
 * @brief Test to check the size of the vector.
 */
TEST_F(VectorFixture, VectorgetSize)
{
  EXPECT_EQ(vec_obj.getSize(), 6);
}

/**
 * @brief Test to check the capacity of the vector.
 */
TEST_F(VectorFixture, VectorgetCapacity)
{
  EXPECT_EQ(vec_obj.getCapacity(), 8);
}

/**
 * @brief Test to check the begin iterator of the vector.
 */
TEST_F(VectorFixture, Vectorbegin)
{
  EXPECT_EQ(*(vec_obj.begin()), 10);
}

/**
 * @brief Test to check the end iterator of the vector.
 */
TEST_F(VectorFixture, Vectorend)
{
  EXPECT_EQ(*(vec_obj.end()), 70);
}

/**
 * @brief Test to check element access in a const vector.
 */
TEST_F(VectorFixture, VectorElementAccess)
{
  EXPECT_EQ(obj_vec[0], 10);
}

/**
 * @brief Test to check string element access in the vector.
 */
TEST_F(VectorFixture, VectorString)
{
  EXPECT_EQ(vec[0], "hello");
}

/**
 * @brief Test to check string element access in the vector.
 */
TEST_F(VectorFixture, VectorString_)
{
  EXPECT_EQ(vec[2], "how");
}