#include<iostream>
#include<thread>
using namespace std;


class SingleTon{

    private:
    SingleTon(){};
    static SingleTon *instance;
    static mutex m;

    public:

    static SingleTon* getInstance()
    {
        if( instance == nullptr)
        {
            m.lock();
            if( instance == nullptr)
            instance = new SingleTon();
            m.unlock();
        }
        return instance;
    }
    void Display()
    {
        cout<<"Singleton Desing has created"<<endl;
    }

    /* Singleton &getInstace() // this is also thread safer in c++
    { static singleton instance;
     return instance;
    }
    */

};

SingleTon * SingleTon:: instance = nullptr;
mutex SingleTon :: m;

int main()
{
    SingleTon *obj = SingleTon::getInstance();
    obj->Display();
}

