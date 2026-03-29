#include<iostream>
using namespace std;

class PaymentMethod{

    public:
    virtual void pay(int amount)=0;

};

class StripeAPI{

    public:
    void payment(int amount)
    {
        cout<<"Payment is done by Stripe : "<<amount<<endl;
    }
};

class RazorPayAPI{

    public:
    void done(int amount)
    {
        cout<<"Payment is done by RazorPay : "<<amount<<endl;
    }
};

class StripeApiAdapter:  public PaymentMethod{

    private:
    StripeAPI stripeapi;

    public:

    void pay( int amount){
        stripeapi.payment(amount);
    }
};

class RazorPayAPIAdapter : public PaymentMethod{

    private:
    RazorPayAPI razorpayapi;

    public:
    void pay( int amount){
        razorpayapi.done(amount);
    }
};

int main(){

   PaymentMethod *payment = new RazorPayAPIAdapter();

   payment->pay(100);

    return 0;
}

