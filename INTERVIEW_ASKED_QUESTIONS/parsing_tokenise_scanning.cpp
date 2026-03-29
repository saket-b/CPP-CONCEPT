#include<iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string str1 = "ram eat mango";

    stringstream ss(str1);
    string token;
    while( getline(ss, token, ' '))
    {
        cout<<token<<endl;
    }

    string str2 = "ram,eat,mango";

    stringstream ss2(str2);
    string token2;
    while( getline(ss2, token2, ','))
    {
        cout<<token2<<endl;
    }

    // parsing 
    //Parsing means analyzing tokens according to a specific structure or grammar.

    // Parsing determines meaning and relationships between tokens.
}