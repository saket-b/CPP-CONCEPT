

class Base {

    public:
    virtual void Display(){

        cout<<"I am in base class"<<endl;
    }
    ~virtual Base(){

    }

};

class Derived : public Base{


        public:

        void Display(){

            cout<<"I am in desrived calss"<<endl;
        }
};

funct( Payment *obj)
{

}

int main(){

    Base *obj = new Derived();
    obj->Display();
    delete obj;
}



int n = 10;
int num = 1;
mutex m;
condition_variable cv;

void even()
{

    for( int i=0; i<(n/2); i++)
    {
        unique_lock<mutex>lock(m);
        cv.wait(lock, [](){return num%2 == 0;}));
        cout<<num<<" ";
        num++;
        cv.notyfy_one();
        

    }



}

void odd()
{
    for( int i=0; i<(n+1/2); i++)
    {
        unique_lock<mutex>lock(m);
        cv.wait(lock, [](){return num%2 == 1;}));
        cout<<num<<" ";
        num++;
        cv.notyfy_one();
        

    }



}

int main(){

    thread t1( odd);
    thread t2(even);

    if( t1.joinable())
        t1.join();
    if( t2.joinable())
        t2.join();
}

void reverseString(string str)
{
/// abcudef
// fedcba
    int n = str.size();

    int i=0, j= n-1;

    while( i < j ){

        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    cout<<str<<endl;
}













