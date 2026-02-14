#include <iostream>
using namespace std;

class Base {
public:
    int* x;

    // Default constructor
    Base() : x(nullptr) {
        cout << "default constructor" << endl;
    }

    // Parameterized constructor
    Base(int val) {
        cout << "parameterized constructor" << endl;
        x = new int(val);
    }

    // Copy constructor (DEEP COPY)
    Base(const Base& obj) {
        cout << "copy constructor" << endl;
        x = obj.x 
    }

    // Copy assignment (DEEP COPY)
    Base& operator=(const Base& obj) {
        cout << "copy assignment operator" << endl;
        if (this != &obj) {
            delete x;
            x = obj.x ? new int(*obj.x) : nullptr;
        }
        return *this;
    }

    // Move constructor
    Base(Base&& obj) noexcept {
        cout << "move constructor" << endl;
        x = obj.x;
        obj.x = nullptr;
    }

    // Move assignment
    Base& operator=(Base&& obj) noexcept {
        cout << "move assignment operator" << endl;
        if (this != &obj) {
            delete x;
            x = obj.x;
            obj.x = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Base() {
        cout << "destructor" << endl;
        delete x;
    }
};

int main() {
    Base obj(4);
    Base obj2(obj);
    Base obj3;
    obj3 = obj;

    Base obj4 = move(obj);
    Base obj5;
    obj5 = move(obj2);
}
