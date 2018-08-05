#include <FIteratorTypes.h>
#include <FVector.h>
#include <gtest/gtest.h>
using namespace shaocong;
TEST(IteratorTest, vectorTest){
    FVector<int> v;
    v.PushBack(1);v.PushBack(2);v.PushBack(3);v.PushBack(4);
    FVector<int>::Iterator i = v.Begin();
    advance(i, 3);
    EXPECT_EQ(*i, 4);
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