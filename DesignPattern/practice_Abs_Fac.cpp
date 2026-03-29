#include<iostream>
using namespace std;

class Vehicle{

    public:

    virtual void drive()=0;
};

class Engine{

    public:
    virtual void type()=0;
};

class Bike : public Vehicle{

    public:

    void drive(){
        cout<<"I am driving Bike"<<endl;
    }
};

class Car : public Vehicle{

    public:

    void drive(){
        cout<<"I am driving Car"<<endl;
    }
};

class BikeEngine : public Engine{

    public:
    void type(){
        cout<<"I am Bike type engine"<<endl;
    }
};

class CarEngine : public Engine{

    public:
    void type(){
        cout<<"I am Car type engine"<<endl;
    }
};

// abstract factory

class Factory{

    public:
    virtual Vehicle* createVehicle()=0;
    virtual Engine * createEngine()=0;
};

class BikeFactory : public Factory{

    public:

    Vehicle * createVehicle(){
        return new Bike();
    }
    Engine * createEngine(){
        return new BikeEngine();
    }
};

class CarFactory : public Factory{

    public:

    Vehicle * createVehicle(){
        return new Car();
    }
    Engine * createEngine(){
        return new CarEngine();
    }
};

int main(){

    Factory *factory = new BikeFactory();

    Vehicle *bike = factory->createVehicle();
    bike->drive();
    Engine *enginebike = factory->createEngine();
    enginebike->type();

}

