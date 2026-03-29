
/*
The Diamond Problem happens in multiple inheritance
 when a class inherits from two classes that both inherit from the same base class.
        A
       / \
      B   C
       \ /
        D
*/
//❌ Problem: Ambiguity
//If A has a function show(), then:

#include<iostream>
using namespace std;

/*class A{

    public:
    void show(){
        cout<<"I am in A class"<<endl;
    }
};

class B : public A{};

class C: public A{};

class D: public B, public C{};

int main(){
    D obj;
    obj.show(); // ambiguous name;
}
*/

// to solve this problem we will use virtual keyword

class A{
    public:
    void show(){
        cout<<"I am in A class"<<endl;
    }
};

class B : virtual public A{};
class C : virtual public A{};

class D : public B, public C{};

int main(){

    D obj;
    obj.show();
}
