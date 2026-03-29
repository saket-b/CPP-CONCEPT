/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<thread>
using namespace std;
mutex m;
condition_variable cv;
int count_var = 1;
void printEven(){
    
    while( count_var < 100)
    {
        unique_lock<mutex>lock(m);
        cv.wait(lock, [](){ return count_var%2 == 0;});
        cout<<this_thread::get_id()<<" "<<count_var<<" "<<endl;
        count_var++;
        cv.notify_one();
    }
}

void printOdd(){
    
    while( count_var < 100)
    {
        unique_lock<mutex>lock(m);
        cv.wait(lock, [](){ return count_var%2 == 1;});
        cout<<this_thread::get_id()<<" "<<count_var<<" "<<endl;
        count_var++;
        cv.notify_one();
    }
}
int main()
{
    thread t1(printOdd);
    thread t2(printEven);
    
    if( t1.joinable())
        t1.join();
    if( t2.joinable())
    {
        t2.join();
    }

    return 0;
}