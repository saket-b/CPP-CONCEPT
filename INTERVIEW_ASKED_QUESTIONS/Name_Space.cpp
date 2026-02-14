#include<iostream>
using namespace std;

namespace saket{

    class Calculator{

        private:
        int x;
        int y;

        public:
        Calculator(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        int sum()
        {
            return x+y;
        }
        int mul()
        {
            return x*y;
        }
    };
}

int main()
{

    saket::Calculator obj(3, 4);
    cout<<obj.sum()<<endl;
    cout<<obj.mul()<<endl;

}