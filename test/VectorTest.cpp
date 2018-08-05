#include <FIteratorTypes.h>
#include <FVector.h>
#include <gtest/gtest.h>
using namespace shaocong;
TEST(IteratorTest, vectorTest){
    FVector<int> v;
    EXPECT_EQ(v.Begin() == v.End(), true);
    v.PushBack(1);v.PushBack(2);v.PushBack(3);v.PushBack(4);
//    EXPECT_EQ(v.Begin() == v.End(), false);
    FVector<int>::Iterator iter = v.Begin();
    EXPECT_EQ(1, *iter);
    advance(iter, 3);
    EXPECT_EQ(*iter, 4);
}

TEST(CapacitTest, vectorTest) {
    FVector<int> v;
    // empty Vector test
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Capacity(), 0);

    // nonempty test
    v.PushBack(10);v.PushBack(20);v.PushBack(30);v.PushBack(40);
    v.PushBack(5);
    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v.Capacity(), 8);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}