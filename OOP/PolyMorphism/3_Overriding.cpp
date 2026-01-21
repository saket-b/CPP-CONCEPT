#include<iostream>
using namespace std;

class Animal{



    public:

    //  virtual void  walk()
    // {
    //     cout<<"Walking"<<endl;
    // }

};

class Dog : public Animal{

    public:
    void walk(){
        cout<<"Dog is waling "<<endl;
    }
};

class Cat : public Animal{

    public:

    void walk()
    {
        cout<<"Cat is walking"<<endl;
    }
};

int main()
{
    Animal *obj = new Dog();
    
   // obj->walk();

}