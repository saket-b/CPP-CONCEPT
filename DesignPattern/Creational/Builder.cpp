#include<iostream>
using namespace std;

//product
class Computer {

    public:
    string cpu;
    int ram;
    string gpu;
};

// builder class 

class ComputerBuilder{
    private:
    Computer comp;
    public:
    ComputerBuilder & setCPU(string c)
    {
        comp.cpu = c;
        return *this;
    }
    ComputerBuilder & setRAM(int r)
    {
        comp.ram = r;
        return *this;
    }

    ComputerBuilder& setGPU(string g)
    {
        comp.gpu = g;
        return *this;
    }

    Computer build(){
        return comp;
    }

};

int main(){

    ComputerBuilder builder;
    Computer c = builder.setCPU("Intel i7")
                .setRAM(16)
                .setGPU("RTX 4070")
                .build();

    cout<<c.cpu<<" "<<c.ram<<" "<<c.gpu<<endl;
}