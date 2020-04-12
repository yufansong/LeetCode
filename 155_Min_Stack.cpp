#include<stack>
#include<iostream>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x<= getMin())
            s2.push(x);
    }
    
    void pop() {
        if(s1.top() == getMin())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};