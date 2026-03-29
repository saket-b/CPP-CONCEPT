#include<iostream>

using namespace std;
mutex m;

class SingleTon{

    private:
    static SingleTon *instance;
    SingleTon(){}

    public:

    static SingleTon * getInstance(){
        
        if( instance == nullptr){
            unique_lock<mutex>lock(m);
            if( instance == nullptr)
                instance = new SingleTon();
        }

        return instance;
    }
    void Display(){
        cout<<"I am inside Singleton class"<<endl;
    }
    SingleTon(const SingleTon &other)= delete;
    SingleTon(SingleTon && other) = delete;

};

SingleTon* SingleTon :: instance = nullptr;
int main(){

        SingleTon *obj = SingleTon:: getInstance();
        obj->Display();

}