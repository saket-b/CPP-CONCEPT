#include<iostream>
using namespace std;

class User{

    private :
    string name;
    int age;
    string gender;

    public:

    void setName(string iName)
    {
        this->name = iName;
    }
    void setAge( int iAge)
    {
        this->age = iAge;
    }
    void setGender(string iGender)
    {
        this->gender = iGender;
    }
    string getName()
    {
        return name;
    }

};

class Student : public User{

    private:
    int psp;
    string batchName;

    public:

    void  setPSP(int ipsp)
    {
        this->psp = ipsp;
    }
    int getPSP()
    {
        return psp;
    }

};

int main()
{
    User *obj = new Student();
    obj->setName("Saket");
    obj->setAge(25);

    cout<<obj->getName()<<endl;
    //obj->setPSP(70);
    return 0;
}