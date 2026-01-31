#pragma once
#include<vector>

class Stack{

    private:
    std::vector<int>st1;
    public:
    void push(int x);
    int pop();
    int size()const;
};