#include<iostream>
using namespace std;

class Base{

    public:
    void Display(){
        cout<<"Inside base class"<<endl;
    }
};
class Derived: public Base{

    public:
    void print(){
        cout<<"Inside Derive class"<<endl;
    }
};

int main(){
    Derived obj2;
    Base *obj = static_cast<Base*>(&obj2);
    if( obj )
    obj->Display();
}