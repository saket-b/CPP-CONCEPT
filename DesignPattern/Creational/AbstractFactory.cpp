#include<iostream>
using namespace std;

class Button{

    public:
    virtual void paint()=0;
    virtual ~Button(){}
};

class CheckBox{

    public:
    virtual void paint() =0;
    virtual ~CheckBox(){}
};

class WindowButton : public Button{

    public:
    void paint(){
        cout<<"window button"<<endl;
    }
};
class WindowCheckBox : public CheckBox{

    public:
    void paint(){
        cout<<"window Checkbox"<<endl;
    }
};

class MacButton : public Button{

    public:
    void paint(){
        cout<<"Mac Button"<<endl;
    }
};

class MacCheckBox : public CheckBox{

    public:
    void paint(){
        cout<<"Mac Check box"<<endl;
    }
};
// abstract factory creating object of family

class GUIFactory{

    public:
    virtual Button *createButton()=0;
    virtual CheckBox*createCheckBox()=0;
    virtual~GUIFactory(){}
};

class WindowFactory : public GUIFactory{

    public:

    Button * createButton(){
        return new WindowButton();
    }

    CheckBox *createCheckBox(){
        return new WindowCheckBox();
    }
};

class MacFactory: public GUIFactory{

    public:
    Button * createButton(){
        return new MacButton();
    }

    CheckBox * createCheckBox(){
        return new MacCheckBox();
    }
};

int main(){
    GUIFactory *factroy = new WindowFactory();

    Button *button = factroy->createButton();
    CheckBox *checkbox = factroy->createCheckBox();
    button->paint();
    checkbox->paint();
}






