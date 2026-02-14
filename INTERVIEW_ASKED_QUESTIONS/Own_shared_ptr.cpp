#include<iostream>
using namespace std;

template<typename T>
class My_Shared_ptr{

    private:
    T *ptr;
    int *refCount ;// this because shared resourse resourse

    public:

    My_Shared_ptr(): ptr(nullptr), refCount(nullptr){};

    My_Shared_ptr(T* other)
    {
        ptr = other;
        refCount = new int(1);

    }
    My_Shared_ptr(const My_Shared_ptr &other)
    {
        ptr = other.ptr;
        refCount = other.refCount;
        cout<<"saket"<<endl;
        if( refCount)
           (*refCount)++;
    }

    My_Shared_ptr& operator = (const My_Shared_ptr &other)
    {
        if( this != &other)
        {
            cleanup();

            ptr = other.ptr;
            refCount = other.refCount;
            cout<<"saket"<<endl;
            if( refCount)
            (*refCount)++;
        }
        return *this;
    }

    void cleanup()
    {
        if( refCount != nullptr)
        {
            (*refCount)--;
            if( *refCount == 0)
            {
                delete ptr;
                delete refCount;
            }
        }
    }




    ~My_Shared_ptr()
    {
        cleanup();
    }

    T& operator*() const{
       return *ptr;
    }

    T* operator->() const{
        return ptr;
    }

    int useCount() const {
        return *refCount;
    }


};

class Base{

    public:

    void Display()
    {
        cout<<"Display function has called"<<endl;
    }
};

int main()
{

    My_Shared_ptr<Base> p1( new Base());

    My_Shared_ptr<Base>p2(p1);

    cout<<p1.useCount()<<endl;
    cout<<p2.useCount()<<endl;
    p1->Display();
}
