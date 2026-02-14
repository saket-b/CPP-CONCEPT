#include<iostream>
using namespace std;


void func3(){
    int x = 25;
    cout<<"function3 = "<<x<<endl;
}

void func2(){
    int y = 30;
    cout<<"function2 = "<<y<<endl;
}

void func1(){
    int z = 35;
    cout<<"function1 = "<<z<<endl;
}


int main()
{
    int v = 50;
    cout<<v<<endl;
    func1();
    return 0;

}