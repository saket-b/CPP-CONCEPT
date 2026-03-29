#include<iostream>
#include<memory>
using namespace std;

class B;

class A {

    public:
    shared_ptr<B>ptrB;
    ~A(){cout<<"A destructor\n";}
};

class B {

    public:
    shared_ptr<A>ptrA;
    ~B(){cout<<"B destructor\n";}
};

int main()
{
    shared_ptr<A>a = make_shared<A>();
    shared_ptr<B>b = make_shared<B>();

    a->ptrB = b;
    b->ptrA = a;

    // cycle problem memory will not free proper b/c reference count will not become zero.
}

//solution 

#include<iostream>
#include<memory>
using namespace std;

class B;

class A {

    public:
    weak_ptr<B>ptrB;
    ~A(){cout<<"A destructor\n";}
};

class B {

    public:
    weak_ptr<A>ptrA;
    ~B(){cout<<"B destructor\n";}
};

int main()
{
    shared_ptr<A>a = make_shared<A>();
    shared_ptr<B>b = make_shared<B>();

    a->ptrB = b;
    b->ptrA = a;
}