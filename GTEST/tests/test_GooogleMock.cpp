

#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

using namespace std;
using::testing::AtLeast;
using ::testing::Return;
using::testing::_;

class DataBaseConnect{

    public:

    virtual bool login(string username, string passsword)
    {
        return true;
    }
    virtual bool login2(string username, string password)
    {
        return true;
    }
    virtual bool logout(string username)
    {
        return true;
    }
    virtual int fetchRecord(){
        return -1;
    }

};

class MockDB :public DataBaseConnect{

    public:
    MOCK_METHOD0(fetchRecord, int());
     MOCK_METHOD1(logout, bool(string username));
      MOCK_METHOD2(login, bool(string username, string password));
    MOCK_METHOD2(login2, bool(string username, string password));
};

class MyDatabase{
    private:
    DataBaseConnect &dbc;

    public:
    MyDatabase(DataBaseConnect&_dbc):dbc(_dbc){}
    int init(string username, string password)
    {
       // int rvalue = rand()%2;
        //if( rvalue % 2 == 0)
        {
      //  if(dbc.login(username, password) != true)
        //{
            if( dbc.login(username, password) != true){

             cout<<"DB Failure"<<endl;
             return -1;
            }
       // }
        else 
        {
            cout<<"DB Success"<<endl;
            return 1;
        }
    }

        return -1;

    }
};

//Expect call
TEST(MyDBTEST, LoginTest)
{
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb, login(_,_)) // there is no need to set user name and password
    .Times(AtLeast(1))
    .WillOnce(Return(true));

    int retValue = db.init("saket", "hello@123");
    EXPECT_EQ(retValue, 1);
}

TEST(MyDBTEST, LoginTestwillOne)
{
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb, login("saket","hello@123")) 
    .Times(AtLeast(1))
    .WillOnce(Return(true));

    int retValue2 = db.init("saket", "hello@123");
    EXPECT_EQ(retValue2, 1);

}


// will repeteadly calll
TEST(MyDBTEST, LoginTestRepeatdlyCall)
{
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb, login("saket","hello@123")) 
    .Times(AtLeast(1))
    .WillRepeatedly(Return(false));

    // int retValue = db.init("saket", "hello@123");
    // EXPECT_EQ(retValue, 1);
    int retValue2 = db.init("saket", "ello@123");
    cout<<"saket: "<<retValue2<<endl;
    EXPECT_EQ(retValue2, -1);

}

//on call
// TEST(MyDBTEST, LoginTestOnCall)
// {
//     MockDB mdb;
//     MyDatabase db(mdb);

//     ON_CALL(mdb, login(_,_)).WillByDefault(Return(true));
//     ON_CALL(mdb, login2(_,_)).WillByDefault(Return(true));
//     int retValue = db.init("Terminator", "willback");
//     EXPECT_EQ(retValue, 1);
    
//     //EXPECT_NE(retValue2, 1);

// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
