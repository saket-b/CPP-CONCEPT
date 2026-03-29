#include<iostream>
using namespace std;

//1 . single responsibility principle
///bad design
/*
class Order{

    public:
    void creatOrder(){}
    void saveToDatabase(){}
    void sendEmail(){}
};
*/

class Order{
    
    public:
    void createOrder(){
        cout<<"order Created"<<endl;
    }
};

class EmailService{

    public:
    void senemail(){
        cout<<"Email sent";
    }
};

//O : Open close principle (OCP)
class PaymentProcessor{

    public:
    void pay( string type)
    {
        if( type == "Credit card")
            cout<<"use credit card"<<endl;
        else if ( type == "UPi")
            cout<<"use by UPI"<<endl;
         
    }
    //problem is if will add bitcoine then i need modify class
};

// correct way 
class Payment{

    public:
    virtual void pay() = 0;
    virtual ~Payment(){};
};

class CreditCard : public Payment{

    public:

    void pay(){
        cout<<"pay by credit card"<<endl;
    }
};

class UPI : public Payment{

    public:
    void pay(){
        cout<<"pay by UPI"<<endl;
    }
};

void ProcessPayment(Payment *payment)
{
    payment->pay();
}

// L : Licksow Subtitutuion Principle
//child should behave how their parent is behaving

/*Liskov Substitution Principle ensures that derived classes can replace base
 classes without altering correctness. A 
 classic violation is the Rectangle-Square problem where overriding 
 behavior breaks expected functionality.
*/
/*“A child class should be usable wherever the parent class is expected, 
without changing correct behavior.” */
class Bird {
public:
    virtual void fly() {
        cout << "Flying\n";
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        cout << "Sparrow flying\n";
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw "Penguins can't fly"; // ❌ LSP violation
    }
};
❌ Why this breaks LSP?
void makeBirdFly(Bird& b) {
    b.fly(); // Expect all birds can fly
}

Sparrow → ✅ works

Penguin → ❌ crashes

👉 Child class changed expected behavior

✅ Correct Design

👉 Separate behavior properly

class Bird {
public:
    virtual void eat() {}
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() override {
        cout << "Sparrow flying\n";
    }
};

class Penguin : public Bird {
    // no fly() → correct design
};

// I : interface segregation principle(ISP)
//client should not depent on methods they don't use
//bad design

class Worker{

    public:
    virtual void work()=0;
    virtual void eat()=0;
};

class Robot : public Worker{

    public:
    void work(){
        cout<<"something";
    }
    void eat(){
        cout<<"something 32"; // meaing less 
    }
};

// good design 

class Workable{

    public:

    virtual void work()=0;

};

class Eatable {

    public:

    virtual void eat() =0;
};

class human : public Workable, public Eatable{

    public:
    void work(){
        cout<<"work is doing"<<endl;
    }
    void eat(){
        cout<<"we are eatong "<<endl;
    }
};

class Robot2 : public Workable{

    public:

    void Workable(){
        cout<<"we are working"<<endl;
    }
};


//D : Dependency Inversion Principle
// Two class should not depend on each other directly
// Bothe should be depend i=on abstractions

class EmailService2 {

    public:
    void send(){
        cout<<"Email sent"<<endl;
    }
};
class OrderService{

    private:
    EmailService2 email;
    public:
    void placeOrder(){
        email.send();
    }
};

//proble is tightly coupled


// good design

class Notification{

    public:
    virtual void send() =0;
};

class EmailNotification : public Notification{

    public:
    void send(){
        cout<<"email send"<<endl;
    }
};

class SMSNotification : public Notification{

    public:
    void send(){
        cout<<" SMS send"<<endl;
    }
};

class OrderService2{

    private:
    Notification *notification;

    public:
    OrderService2(Notification *n): notification(n){}
    void placeorder(){

        notification->send();
    }
};
// use
int main(){

    EmailNotification email;
    OrderService2 order(&email);

    order.placeorder();
}



