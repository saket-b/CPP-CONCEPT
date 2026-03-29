#include<iostream>
using namespace std;

class HotelSearch{

    private:

    string checkinDate;
    string checkOutDate;
    int guest;
    int room ;

    friend class HotelSearchBuilder;
    public:
    void display(){
        cout<<checkinDate<<" "<<checkOutDate<<" "<<guest<<" "<<room<<endl;
    }
};

class HotelSearchBuilder{


    public:

    HotelSearch  req;

    HotelSearchBuilder & setCheckInDate(const string & checkIndate){
        req.checkinDate = checkIndate;
        return *this;
    }

    HotelSearchBuilder & setCheckOutDate(const string &checkoutDate)
    {
        req.checkOutDate = checkoutDate;
        return *this;
    }

    HotelSearchBuilder & setGuest(int no_of_guest)
    {
        req.guest = no_of_guest;
        return *this;
    }

    HotelSearchBuilder & setRoom(int no_of_room)
    {
        req.room = no_of_room;
        return *this;
    }

    HotelSearch build()
    {
        return req;
    }




};


int main(){


    HotelSearch req = HotelSearchBuilder()
    .setCheckInDate("10-03-2005")
    .setCheckOutDate("13-09-2026")
    .setRoom(2)
    .setGuest(2)
    .build();

    req.display();
}
