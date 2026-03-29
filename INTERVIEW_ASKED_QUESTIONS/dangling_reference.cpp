#include <iostream>
using namespace std;

int& getValue()
{
    int x = 10;   // local variable
    return x;     // returning reference
}

int main()
{
    int& ref = getValue();

    cout << ref;  // undefined behavior
}