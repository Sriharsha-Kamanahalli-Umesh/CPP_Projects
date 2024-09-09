#include "my_vector.h"
#include "gtest/gtest.h"

class VectorFixture : public testing::Test {
  protected:
      Myvector<int> vec_obj = {10, 20, 30, 40, 50, 60};
      const Myvector<int> obj_vec = {10, 20, 30, 40};

      Myvector<std::string> vec = {"hello", "sriharsha", "how", "are", "you"};
};

TEST_F(VectorFixture, VectorInitialization) {
  vec_obj.push_back(70);
  vec_obj.push_back(80);

  Myvector<int> test_vec_obj;
  for(std::size_t i=0; i<vec_obj.getSize(); i++) {
    test_vec_obj.push_back(vec_obj[i]);
  }
  for(std::size_t i=0; i<vec_obj.getSize(); i++) {
    EXPECT_EQ(vec_obj[i], test_vec_obj[i]);
  }
  
}

TEST_F(VectorFixture, VectorgetSize) {
  EXPECT_EQ(vec_obj.getSize(), 6);
}

TEST_F(VectorFixture, VectorgetCapacity) {
  EXPECT_EQ(vec_obj.getCapacity(), 8);
}

TEST_F(VectorFixture, Vectorbegin) {
  EXPECT_EQ(*(vec_obj.begin()), 10);
}

TEST_F(VectorFixture, Vectorend) {
  EXPECT_EQ(*(vec_obj.end()), 70);
}

TEST_F(VectorFixture, VectorElementAccess) {
  EXPECT_EQ(obj_vec[0], 10);
}

// TEST_F(VectorFixture, VectorElementAccessWithException) {
//   try {
//     vec_obj[10];
//   }
//   catch(const exception::OutofRangeException &e) {
//     EXPECT_STREQ(e.what(), "Index out of range");
//   }
// }

// TEST_F(VectorFixture, VectorElementAccessWithExceptionWithConstFunction) {
//   try {
//     obj_vec[10];
//   }
//   catch(const exception::OutofRangeException &e) {
//     EXPECT_STREQ(e.what(), "Index out of range");
//   }
// }

TEST_F(VectorFixture, VectorString) {
  EXPECT_EQ(vec[0], "hello");
}

TEST_F(VectorFixture, VectorString_) {
  EXPECT_EQ(vec[2], "how");
}