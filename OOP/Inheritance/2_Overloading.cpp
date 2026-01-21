#include<iostream>
using namespace std;

class Calculator{



    public:

    int add( int a, int b)
    {
        return a+b;
    }

    int add( int a, int b, int c)
    {
        return a+b+c;
    }

    double add( double a, double b)
    {
        return a+b;
    }

};

int main()
{
    Calculator *obj = new Calculator();
    
    cout<<obj->add(1,2)<<endl;
    cout<<obj->add(1,2,3)<<endl;
    cout<<obj->add(8.5, 6.5)<<endl;

}