#include "../Vector.h"
#include <gtest/gtest.h>
#include <stdio.h>
using namespace sctoys;
TEST(advanceTest, VectorTest) {
  Vector<int> v;
  v.PushBack(10);
  v.PushBack(20);
  v.PushBack(30);
  v.PushBack(40);
  Vector<int>::iterator iter = v.Begin();
  advance(iter, 2);
  EXPECT_EQ(*iter, 30);
}

TEST(PushBackTest, VectorTest) {
  Vector<int> v;
  v.PushBack(10);
  v.PushBack(20);
  v.PushBack(30);
  EXPECT_EQ(v.Size(), 3);
  EXPECT_EQ(*v.Begin(), 10);
  EXPECT_EQ(v.End() - v.Begin(), 3);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}