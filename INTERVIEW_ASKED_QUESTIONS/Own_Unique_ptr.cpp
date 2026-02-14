#include<iostream>

using namespace std;
template<typename T>
class My_Unique_ptr{

    public:
    T *ptr;

    My_Unique_ptr():ptr(nullptr){}

    My_Unique_ptr(T *other)
    {
        ptr = other;
    }
   
    
     My_Unique_ptr( My_Unique_ptr&& other)
    {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    
    My_Unique_ptr& operator =(const My_Unique_ptr && other)
    {
        if( this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~My_Unique_ptr()
    {
        if( ptr != nullptr)
        {
            delete ptr;
        }
    }

    T* operator->()
    {
        return ptr;
    }

    T& operator *()
    {
        return *ptr;
    }
    
    My_Unique_ptr (const My_Unique_ptr & ) = delete;
    My_Unique_ptr & operator = (const My_Unique_ptr&) = delete;

};

class Base{

    public:
    void Display(){
        cout<<"Inside Base class"<<endl;
    }
};

int main()
{
    My_Unique_ptr<Base>obj(new Base());
    
    My_Unique_ptr<Base>obj2 = move(obj);

    obj->Display();
    obj2->Display();

}