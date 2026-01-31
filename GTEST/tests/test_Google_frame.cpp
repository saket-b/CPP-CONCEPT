#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace std;
using::testing::AtLeast;
using ::testing::Return;
using::testing::_;

class Check{

    private:
    int val;
    public:
    Check() :val(0){}
    void setValue(int newVal){
        this->val= newVal;
    }
    int getVal()
    {
        return this->val;
    }

};


TEST(TESTNAME, Check_test_without_Fixture)
{
    // arrange
    Check *c1 = new Check();

    //act
    c1->setValue(100);

    //assert
    ASSERT_EQ(c1->getVal(), 100);

}

class TF: public testing :: Test{

    public:
    Check *c2;
    void SetUp(){
       c2= new Check();
    }
    void Teardown(){
        delete c2;
    }

};


// test name shoulb be same as test fixture
TEST_F(TF, Check_test_without_Fixture)
{
    // arrange
    // will move in text fixture

    //act
    c2->setValue(100);

    //assert
    ASSERT_EQ(c2->getVal(), 100);

}


TEST(TESTNAME, Check_test_without_Fixture2)
{
    // arrange
    Check *c1 = new Check();

    //act
    c1->setValue(10);

    //assert
    ASSERT_EQ(c1->getVal(), 10);

}

// here for every obejec we cre creating obeject repetive work
// So, we will move at common place




TEST(TESTNAME, SubtestName)
{
    //EXPECT_TRUE(100 ==10);
    ASSERT_TRUE(100 == 100);
    
    cout<<"=== Test Called1 ==="<<endl;
   // EXPECT_CALL(true);
}

TEST(TESTNAME, SubtestName2)
{
  
    //ASSERT_TRUE(100 == 10);
      EXPECT_TRUE(100 ==100);
    cout<<"==Test Called2 =="<<endl;
   // EXPECT_CALL(true);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
