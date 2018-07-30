#include <IteratorTypes.h>
#include <Vector.h>
#include <gtest/gtest.h>
using namespace sctoys;
TEST(IteratorTest, vectorTest){
    Vector<int> v;
    v.PushBack(1);v.PushBack(2);v.PushBack(3);v.PushBack(4);
    Vector<int>::Iterator i = v.Begin();
    advance(i, 3);
    EXPECT_EQ(*i, 4);
}
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}