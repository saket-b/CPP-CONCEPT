/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
class Student{
    private:
    string name;
    int age;
    
    public:
    Student(string iName, int iAge)
    {
        this->name = iName;
        this->age = iAge;
    }
    
    void * operator new(size_t size)
    {
        cout<<"operator overloading has called "<<endl;
        void *ptr = malloc(size);
        return ptr; 
    }
    void Display()
    {
        cout<<"Name = "<<name<<endl;
        cout<<"Age = "<<age<<endl;
    }
    
    void operator delete(void *ptr)
    {
        cout<<"Delete operator overloading called"<<endl;
        if( ptr != nullptr)
        free(ptr);
    }
    
    
};
int main()
{
    Student *obj = new Student("Saket", 25);
    obj->Display();
    delete obj;

    return 0;
}