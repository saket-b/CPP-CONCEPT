#include<iostream>

using namespace std;

class Payment {

    public:

    virtual void pay(int amount)=0;
    virtual  ~Payment(){};
};

class CreditCard : public Payment{

    public:
    void pay(int amount)
    {
        cout<<"Payment done via Credit Card : "<<amount<<endl;
    }
};

class DebitCard : public Payment{

    public:

    void pay( int amount)
    {
        cout<<"Payment done via Debit Card : "<<amount<<endl;
    }
};

class PaymentContext {

    private:

    Payment *strategy;

    public:

    PaymentContext(Payment *s) : strategy(s){}

    void executePayment(int amount)
    {
        strategy->pay(amount);
    }

};

int main(){

    Payment *strategy = new CreditCard();

    PaymentContext *context = new PaymentContext(strategy);
    context->executePayment(100);
    delete context;
    delete strategy;
    
}