#include<iostream>
#include <vector>
using namespace std;


class NotificationObserver{

    public:
    virtual void notify(string message) =0;
    virtual ~NotificationObserver(){}
};

class EmailNotification : public NotificationObserver{

    public:
    void notify(string message)
    {
        cout<<"Email sent : "<<message<<endl;
    }
};

class SMSNotifiction: public NotificationObserver{

    public:
    void notify(string message)
    {
        cout<<"SMS sent : "<<message<<endl;
    }
};

class PushNotification: public NotificationObserver{
    public:
    void notify(string message)
    {
        cout<<"Push Notification: "<<message<<endl;
    }
};
// Booking service

class BookingService{

    private:
    vector<NotificationObserver*>observers;

    public:
    void subscribe(NotificationObserver*obs){
        observers.push_back(obs);
    }
    void notifyAll(string message)
    {
        for(  auto const obs: observers)
        {
            obs->notify(message);
        }
    }
    void bookHotel(string user)
    {
        cout<<user<<" booked a hotel"<<endl;
        notifyAll("Hotel Booking confirmed for " + user);
    }
};

int main(){

    BookingService booking;
    EmailNotification email;
    SMSNotifiction sms;
    PushNotification push;

    booking.subscribe(&email);
    booking.subscribe(&sms);
    booking.subscribe(&push);
    booking.bookHotel("saket");
}

