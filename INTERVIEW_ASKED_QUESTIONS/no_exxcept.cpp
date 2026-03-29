#include<iostream>

using namespace std;

double divide(int a, int b) noexcept
{

    if( b == 0)
    {
        throw "B should not be zero";
        terminate();
    }
    return a/b;
}

void Display()
{
    cout<<"I am inside Display function"<<endl;
}

int main()
{
    cout<<(divide(4, 0))<<endl;
    Display();

}