#include <iostream>
#include<string.h>
using namespace std;

class String
{
  private:
    char *s;
    int size;

  public:
    String(const char *str)
    {
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }
    ~String()
    {
        delete[] s;
    }
    String(const String &old_str)
    {
        size = old_str.size;
        s = new char[size + 1];
        strcpy(s, old_str.s);
    }
    String & operator =( String &old_str)
    {
        if( this == &old_str)
            return *this;
        
        delete []s;
        size = old_str.size;
        s = new char[size + 1];
        strcpy(s, old_str.s);
        return *this;
    }
    void print()
    {
        cout << s << endl;
    }

    void change(const char *str)
    {
        delete[] s;
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }
};

int main()
{
    String str1("GeeksQuiz");

    // Create str2 from str1
    String str2 = str1;
    str1.print();
    str2.print();

    // Update the str2 object
    str2.change("GeeksforGeeks");

    str1.print();
    str2.print();
    return 0;
}