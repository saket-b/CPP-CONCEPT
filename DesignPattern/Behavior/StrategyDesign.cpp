#include<iostream>
using namespace std;

// Stretegy intefaces
class PaymentStrategy{

    public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy(){}
};

// Concrete strategies
class CreditCardPayment : public PaymentStrategy{

    public:
    void pay(int amount){
        cout<<"Paid "<<amount<<" using Credit card"<<endl;
    }
};

class PayPalPayment : public PaymentStrategy{

    public:
    void pay( int  amount){
        cout<<"Paid "<<amount<<" using PayPal"<<endl;
    }

};

// context class 
// uses strategy 
class PaymentContext {

    private:
    PaymentStrategy *strategy;

    public:
    PaymentContext(PaymentStrategy*s) : strategy(s){}
    void executePayment(int amount){
        strategy->pay(amount);
    }
};

int main(){

    PaymentStrategy *strategy = new CreditCardPayment();
    PaymentContext context(strategy);
    context.executePayment(300);
}

