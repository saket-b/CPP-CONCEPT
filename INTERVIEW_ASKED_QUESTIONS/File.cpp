#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream file("data.csv");
    string word;
    while( getline(file, word))
    {
        cout<<word<<endl;
    }

    file.close();

}