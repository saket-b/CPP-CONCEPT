/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class PaymentMethod{
    
    public:
    virtual bool pay(double amount)=0;
    virtual~ PaymentMethod(){};
};

class DebitCard : public PaymentMethod{
    
    public:
    bool pay( double amount)
    {
        cout<<"Payment has done via DebitCard:"<<amount<<endl;
        return true;
    }
};

class CreditCard : public PaymentMethod{
    
    public:
    bool pay( double amount)
    {
        cout<<"Payment has done via CreditCard:"<<amount<<endl;
        return true;
    }
};

class UPI : public PaymentMethod{
    
    public:
    bool pay( double amount)
    {
        cout<<"Payment has done via UPI:"<<amount<<endl;
        return true;
    }
};

class Cash : public PaymentMethod{
    
    public:
    bool pay( double amount)
    {
        cout<<"Payment has done via Cash:"<<amount<<endl;
        return true;
    }
};

class PaymentProcessor{
    
    public:
    bool processPayment(PaymentMethod *method, double amount)
    {
        return method->pay(amount);
    }
    
    
};
int main()
{
    PaymentProcessor processor;
    PaymentMethod *method =  new Cash();
    
    if( processor.processPayment(method, 500))
    {
        cout<<"payment Successfull...\n";
    }
    else 
    {
        cout<<"payment Fail...\n";
        
    }
    delete method;
    return 0;
}