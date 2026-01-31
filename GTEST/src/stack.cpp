#include "stack.h"


void Stack:: push(int x){

    st1.push_back(x);
}

int Stack :: pop()
{
    if( st1.size() > 0)
    {
        int x = st1.back();
        st1.pop_back();
        return x;
    }
    else 
        return -1;
}

int Stack:: size() const{
    return st1.size();
}