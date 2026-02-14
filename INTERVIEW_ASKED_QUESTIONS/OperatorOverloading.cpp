#include<iostream>
using namespace std;

class Number{

    private :
    int x;

    public :
    Number( int iX)
    {
        x = iX;
    }

    Number & operator+(Number &temp)
    {
        if( this != &temp)
        {
            this->x += temp.x;
        }
        return *this;
    }
    void Display()
    {
        cout<<"X= "<<x<<endl;
    }
};

int main()
{
    Number num1(6);

    Number num2(7);

    Number num3 = num1+num2;
    num3.Display();
}