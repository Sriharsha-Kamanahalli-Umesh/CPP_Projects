#include "my_vector.h"
#include "gtest/gtest.h"

// /**
//  * @brief Test fixture for Myvector tests.
//  */
// class VectorFixture : public testing::Test
// {
// protected:
//   Myvector<int> vec_obj = {10, 20, 30, 40, 50, 60};
//   const Myvector<int> obj_vec = {10, 20, 30, 40};

//   Myvector<std::string> vec = {"hello", "sriharsha", "how", "are", "you"};
// };

// /**
//  * @brief Test to check vector initialization and push_back functionality.
//  */
// TEST_F(VectorFixture, VectorInitialization)
// {
//   vec_obj.push_back(70);
//   vec_obj.push_back(80);

//   Myvector<int> test_vec_obj;
//   std::cout << "Size : " << vec_obj.size() << "\n";
//   std::cout << "Capacity : " << vec_obj.capacity() << "\n";
//   for (std::size_t i = 0; i < vec_obj.size(); i++)
//   {
//     test_vec_obj.push_back(vec_obj[i]);
//   }
//   for (std::size_t i = 0; i < vec_obj.size(); i++)
//   {
//     EXPECT_EQ(vec_obj[i], test_vec_obj[i]);
//   }

//   for (std::size_t i = 0; i < vec_obj.size(); i++)
//   {
//     test_vec_obj.pop_back();
//   }
//   for (std::size_t i = 0; i < vec_obj.size(); i++)
//   {
//     EXPECT_EQ(test_vec_obj.size(), 0);
//   }


// }

// /**
//  * @brief Test to check the size of the vector.
//  */
// TEST_F(VectorFixture, VectorgetSize)
// {
//   EXPECT_EQ(vec_obj.size(), 6);
// }

// /**
//  * @brief Test to check the capacity of the vector.
//  */
// TEST_F(VectorFixture, VectorgetCapacity)
// {
//   EXPECT_EQ(vec_obj.capacity(), 8);
// }

// /**
//  * @brief Test to check the begin iterator of the vector.
//  */
// TEST_F(VectorFixture, Vectorbegin)
// {
//   EXPECT_EQ(*(vec_obj.begin()), 10);
// }

// /**
//  * @brief Test to check the end iterator of the vector.
//  */
// TEST_F(VectorFixture, Vectorend)
// {
//   EXPECT_EQ(*(vec_obj.end()), 70);
//   std::cout << "last address : " << *(vec_obj.end()) << "\n";
//   std::cout << "last address : " << *(vec_obj.end()-1) << "\n";
// }


// /**
//  * @brief Test to check the front iterator of the vector.
//  */
// TEST_F(VectorFixture, Vectorfront)
// {
//   auto va = vec_obj.front();
//   va = 40;
//   EXPECT_EQ(vec_obj.front(), 10);
// }

// /**
//  * @brief Test to check the back iterator of the vector.
//  */
// TEST_F(VectorFixture, Vectorback)
// {
//   std::cout << "last address : " << (vec_obj.size()) << "\n";
//   EXPECT_EQ(vec_obj.back(), 60);
// }

// /**
//  * @brief Test to check element access in a const vector.
//  */
// TEST_F(VectorFixture, VectorElementAccess)
// {
//   EXPECT_EQ(obj_vec[0], 10);
// }

// /**
//  * @brief Test to check string element access in the vector.
//  */
// TEST_F(VectorFixture, VectorString)
// {
//   EXPECT_EQ(vec[0], "hello");
// }

// /**
//  * @brief Test to check string element access in the vector.
//  */
// TEST_F(VectorFixture, VectorString_)
// {
//   EXPECT_EQ(vec[2], "how");
// }


// TEST_F(VectorFixture, VectorInsert)
// {
//   vec_obj.insert(2, 25);
//   EXPECT_EQ(vec_obj[2], 25);
//   EXPECT_EQ(vec_obj.size(), 7);
// }

// TEST_F(VectorFixture, VectorErase)
// {
//   vec_obj.erase(3);
//   EXPECT_EQ(vec_obj[3], 50);
//   EXPECT_EQ(vec_obj.size(), 5);
// }

// TEST_F(VectorFixture, VectorClear)
// {
//   vec_obj.clear();
//   EXPECT_EQ(vec_obj.size(), 0);
//   // EXPECT_EQ(vec_obj.capacity(), 0);
// }


// TEST(Test, VectorCopyConstructor)
// {
//   Myvector<int> vec1 = {1, 2, 3, 4, 5};
//   Myvector<int> vec2 = vec1; // Copy constructor
//   EXPECT_EQ(vec2.size(), vec1.size());
//   for (std::size_t i = 0; i < vec1.size(); i++)
//   {
//     EXPECT_EQ(vec2[i], vec1[i]);
//   }
// }

// TEST(Test, VectorCopyAssignment)
// {
//   Myvector<int> vec1 = {1, 2, 3, 4, 5};
//   Myvector<int> vec2;
//   vec2 = vec1; // Copy assignment
//   EXPECT_EQ(vec2.size(), vec1.size());
//   for (std::size_t i = 0; i < vec1.size(); i++)
//   {
//     EXPECT_EQ(vec2[i], vec1[i]);
//   }
// }

// // Example for Named Return Value Optimization (NRVO)
// // These are the compiler optimizations, which avoid the calling of move constructor or copy constructor.
// // Here the compiler optimizes the code to avoid the extra copy or move operations by writting the return value directly to the memory location of the caller.
// Myvector<int> createVectorNRVO() {
//   Myvector<int> v{400, 500, 600};
//   return v; // NRVO may apply, but if not, move constructor is used
// }
// // ...existing code...

// // Example for Return Value Optimization (RVO)
// // These are the compiler optimizations, which avoid the calling of move constructor or copy constructor.
// // Here the compiler optimizes the code to avoid the extra copy or move operations by writting the return value directly to the memory location of the caller.
// // 
// Myvector<int> createVectorRVO() {
//   // Directly return a temporary object (no named variable)
//   return Myvector<int>{400, 500, 600}; // RVO will likely be applied here
// }

// TEST(Test, VectorMoveConstructorRVO)
// {
//   Myvector<int> vec1 = {1, 2, 3, 4, 5};
//   Myvector<int> vec2 = createVectorRVO(); // Move constructor
//   EXPECT_EQ(vec2.size(), 3);
//   // EXPECT_EQ(vec1.size(), 0);
// }

// TEST(Test, VectorMoveConstructorNRVO)
// {
//   Myvector<int> vec1 = {1, 2, 3, 4, 5};
//   Myvector<int> vec2 = createVectorNRVO(); // Move constructor
//   EXPECT_EQ(vec2.size(), 3);
//   // EXPECT_EQ(vec1.size(), 0);
// }

// TEST(Test, VectorMoveAssignment)
// {
//   Myvector<int> vec1 = {1, 2, 3, 4, 5};
//   Myvector<int> vec2;
//   vec2 = std::move(vec1); // Move assignment
//   EXPECT_EQ(vec2.size(), 5);
//   EXPECT_EQ(vec1.size(), 0);
// }


TEST(TestVector, TestCopyConstructor)
{
    Myvector<int> original = {1, 2, 3, 4, 5};
    Myvector<int> copy = original; // Copy constructor
    EXPECT_EQ(copy.size(), original.size());
    for (std::size_t i = 0; i < original.size(); ++i) {
      EXPECT_EQ(copy[i], original[i]);
    }
}

TEST(TestVector, TestMoveConstructor)
{
    Myvector<int> original = {1, 2, 3, 4, 5};
    Myvector<int> copy = std::move(original); // Move constructor
    EXPECT_EQ(copy.size(), 5);
    EXPECT_EQ(original.size(), 0);

}

TEST(TestVector, TestCopyAssignment)
{
    Myvector<int> original = {1, 2, 3, 4, 5};
    Myvector<int> copy;
    copy = original; // Copy assignment
    EXPECT_EQ(copy.size(), original.size());
    for (std::size_t i = 0; i < original.size(); ++i) {
      EXPECT_EQ(copy[i], original[i]);
    }

}

TEST(TestVector, TestCopyAssignment1)
{
    Myvector<int> original = {1, 2, 3, 4, 5};
    Myvector<int> copy;
    original = original; // Copy assignment

}

TEST(TestVector, TestMoveAssignment)
{
    Myvector<int> original = {1, 2, 3, 4, 5};
    Myvector<int> copy;
    copy = std::move(original); // Move assignment
    EXPECT_EQ(copy.size(), 5);
    EXPECT_EQ(original.size(), 0);

}