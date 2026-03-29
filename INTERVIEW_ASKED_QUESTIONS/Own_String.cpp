/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;
class String{
    
    public:
    char *str;
    
    String(){ str = nullptr;}
    String( const char *other)
    {
        if( other != nullptr)
        {
            int n = strlen(other);
            str = new char[n+1];
            strcpy(str, other);
            str[n]='\0';
        }
        else  {
            str = nullptr;
        }
    }
    
    String( const String &other)
    {
        if( other.str)
        {
            int n = strlen(other.str);
            str = new char[n+1];
            strcpy(str, other.str);
            str[n]='\0';
        }
        else {
            str = nullptr;
        }
    }

    String( String && other){

        str = other.str;
        other.str = nullptr;
    }

    String & operator =(const String &other)
    {
        cout<< "operator overloading call"<<endl;
        if( this != &other)
        {
            int n = strlen(other.str);
            str = new char[n+1];
            strcpy(str, other.str);
            str[n]='\0';

        }

        return *this;
    }

};
int main()
{
    String s("saket");
    cout<<s.str<<endl;

    String s2 = std::move(s);
    cout<<s2.str<<endl;

    String s3;

    s3 = s2;
    cout<<s3.str<<endl;


    return 0;
}