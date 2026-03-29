#include<iostream>
using namespace std;

int  add(int x, int y)
{
    return x+y;
}

int sub(int x, int y)
{
    return x-y;
}

int main()
{
    int (*ptr)(int, int) ;

    ptr = &add;

    cout<<ptr(1, 2)<<endl;

    ptr = &sub;
    cout<<sub(5,4)<<endl;

}