#include<iostream>
using namespace std;

class PaymentProcessor{

    public:
    virtual void pay(int amount) =0;
    virtual ~PaymentProcessor(){}
};
//stripe API

class StripeAPI{

    public:
    void makePayment(int amount){
        cout<<"Stripe payment of "<<amount<<endl;
    }

};

// PaypalUPI

class PayPalAPI{

    public:
    void sendPayment(int amount)
    {
        cout<<"PayPal payment of "<<amount<<endl;
    }
};

// adapter class 

class StripeAdapter : public PaymentProcessor{

    private:
    StripeAPI stripeapi;

    public:
    void pay( int amount)
    {
        stripeapi.makePayment(amount);
    }
};

class PapPalAdapter : public PaymentProcessor{

    private:
    PayPalAPI paypalapi;
    public:

    void pay( int amount){

        paypalapi.sendPayment(amount);
    }
};

int main(){

    PaymentProcessor *payment;
    payment = new StripeAdapter();
    payment->pay(100);
    payment = new PapPalAdapter();
    payment->pay(300);
    delete payment;
}

