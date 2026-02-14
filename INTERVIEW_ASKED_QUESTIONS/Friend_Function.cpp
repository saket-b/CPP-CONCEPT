#include<iostream>

using namespace std;

class Base {

    private:
    int x;
    int y;

    public:
    Base(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    

    friend void Display(Base *obj);
};

void  Display(Base *obj)
{
    cout<<"X ="<<obj->x<<endl;
    cout<<"Y = "<<obj->y<<endl;
}

int main()
{
    Base *obj = new Base(2, 3);
    Display(obj);
}