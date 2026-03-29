#include<iostream>
using namespace std;

class Notification{

    public:

    virtual void send()=0;
    virtual ~Notification(){};
};

class Email : public Notification{

    public:

    void send(){
        cout<<"Email Notification has sent"<<endl;
    }
};

class SMS : public Notification{

    public:

    void send(){
        cout<<"SMS Notification has  sent"<<endl;
    }
};

class WhatsApp : public Notification{

    public:

    void send(){
        cout<<"WhatsApp Notification has  sent"<<endl;
    }
};

class OrderPlaced{

    private:
    vector<unique_ptr<Notification>>notifications;
    public:

    void subscribe(unique_ptr<Notification>notific)
    {
        notifications.push_back(move(notific));
    }
    void notifyAll(){
        for( const auto &obs : notifications)
        {
            obs->send();
        }
    }

    void Book(string user)
    {
        cout<<"User "<<user<<"has booked hotel"<<endl;
        notifyAll();
    }

    

};

int main(){

    OrderPlaced order;
    
    order.subscribe( make_unique<Email>());
    order.subscribe( make_unique<SMS>());
    order.subscribe( make_unique<WhatsApp>());

    order.Book("saket");
}