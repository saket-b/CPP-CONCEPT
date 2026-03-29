#include<iostream>
using namespace std;
using namespace std;

class Vehicle{

    public:
    virtual void display()=0;
    virtual ~Vehicle(){};
};

class FourWheeler : public Vehicle{

    public:

    void display(){
        cout<<"I am driving fourwheeler"<<endl;
    }
};

class TwoWheeler : public Vehicle{

    public:

    void display(){
        cout<<"I am driving Two wheeler"<<endl;
    }
};

class FactorVehicle {

    public:

    virtual Vehicle* createVehicle()=0;
    virtual ~FactorVehicle(){};
};

class TwoWheelerFactory : public FactorVehicle{

    public:

    Vehicle *createVehicle()
    {
        return new TwoWheeler();
    }
};

class FourWheelerFactory : public FactorVehicle{

    public:

    Vehicle *createVehicle()
    {
        return new FourWheeler();
    }
};

int main(){

    FactorVehicle *TwoWheeler = new TwoWheelerFactory();

    Vehicle *vehicle = TwoWheeler->createVehicle();
    vehicle->display();

}
