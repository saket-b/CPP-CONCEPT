#include<iostream>
#include<thread>
using namespace std;

//1 Function pointer
void fun( int x)
{
    while(x--> 0)
    {
        cout<<x<<endl;
    }
}
int main()
{
    thread t(fun, 10);
    t.join();

}

//2 Lamda Expression

int main(){

    auto fun = [](int x){
        while( x--> 0)
        {
            cout<<x<<endl;
        }
    };

    thread t(fun, 10);
    t.join();
    return 0;
}

//3. functor ( function object)

class Base{

    public:
    void operator()(int x)
    {
        while( x-- > 0)
        {
            cout<<x<<endl;
        }
    }
};
int main()
{
    thread t((Base()), 10);
    t.join();
    return 0;
}

//4. non static member function

class Base{

    public:

    void run(int x)
    {
        while(x--> 0)
        {
            cout<<x<<endl;
        }
    }
};

int main()
{
    Base b;
    thread t(&Base ::run, &b, 10);
    t.join();
    return 0;
}

// 5. static member function

class Base{

    static void run(int x)
    {
        while( x-- > 0)
        {
            cout<<x <<endl;
        }
    }
};

int main()
{
    thread t(&Base::run, 10);
    t.join();
    return 0;
}

