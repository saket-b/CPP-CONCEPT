#include<iostream>

using namespace std;

class Vehicle{

    public:

    virtual void Drive() = 0;
    virtual ~Vehicle(){};
};

class Car : public Vehicle{

    public:
    void Drive(){
        cout<<"I am driving Car"<<endl;
    }
};
class Bike : public Vehicle{

    public:
    void Drive(){
        cout<<"I am driving Bike"<<endl;
    }
};
// for object creation
// factory
class VehicleFactory{

    public:
    virtual Vehicle* createVehicle()=0;
    virtual ~VehicleFactory(){};
};

class CarFactory : public VehicleFactory{

    public:

    Vehicle * createVehicle(){
        return new Car();
    }

};

class BikeFactory : public VehicleFactory{

    public:

    Vehicle * createVehicle(){
        return new Bike();
    }

};

int main(){

    VehicleFactory *factory = new CarFactory();
    Vehicle *v = factory->createVehicle();
    v->Drive();
    delete v;
    delete factory;
}
