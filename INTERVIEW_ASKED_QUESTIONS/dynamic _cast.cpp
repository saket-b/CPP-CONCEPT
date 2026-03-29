#include<iostream>
using namespace std;

class Base{

    public:

    virtual void Display(){

            cout<<"I am inside base class"<<endl;
    }
};

class Derived : public Base{

    public:
    void Display()
    {
        cout<<"i am inside derived class"<<endl;
    }


};

void checkpoint(Base *obj)
{

    // check dervide object or not;

    Derived *derivedobj = dynamic_cast<Derived*>(obj);

    if( derivedobj)
    {
        cout<<"saket"<<endl;
        derivedobj->Display();
    }
}

int main()
{
    Base *obj = new Derived();

    checkpoint(obj);
}
