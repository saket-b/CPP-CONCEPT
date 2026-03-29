#include<iostream>
using namespace std;

class Coffee{

    public:
    virtual int cost() =0;
    virtual ~Coffee(){}
};

class BasicCoffee : public Coffee{

    public:
    int cost(){
        return 5;
    }
};

// Decorator class 
//Decorator wraps another Coffee object.
class CoffeDecorator : public Coffee{

    protected:
    Coffee *coffee;

    public:
    CoffeDecorator(Coffee*c): coffee(c){}
};

// Milk Decorator 
class MilkDecorator : public CoffeDecorator{
    public:
    MilkDecorator(Coffee *c) : CoffeDecorator(c){}
    int cost(){
        return coffee->cost()+2;
    }
};

// sugar Decorator 
class SugarDecorator : public CoffeDecorator{
    public:
    SugarDecorator(Coffee *c) : CoffeDecorator(c){}
    int cost(){
        return coffee->cost() + 1;
    }
};

int main()
{
    Coffee * coffee = new BasicCoffee();
    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);
    cout<<coffee->cost()<<endl;
}

