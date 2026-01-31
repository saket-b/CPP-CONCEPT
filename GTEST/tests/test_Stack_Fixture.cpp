#include <gtest/gtest.h>
#include "stack.h"
struct stackTest : public testing :: Test{
    
    Stack st1;
    void SetUp()  override{
        int value[] = {1,2,3,4,5,6,7,8,9};
        for( auto &val: value){
            st1.push(val);
        }
    }
    //void TearDown(){}
};

TEST_F(stackTest, PopTest)
{
    std::cout<<"size= "<<st1.size()<<std::endl;
    int lastPoppedValue = 9;
    while( lastPoppedValue >= 1)
    {   ASSERT_EQ(st1.pop(), lastPoppedValue);
        lastPoppedValue--;
    }

}
TEST_F(stackTest, PopTest2)
{
    int size = st1.size();
    for( ; size>0; size--)
       ASSERT_NE(st1.pop(), -1);

}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}