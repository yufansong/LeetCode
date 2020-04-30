#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> l;
        stack<int> star;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                l.push(i);
            else if(s[i] == '*')
                star.push(i);
            else{
                if(l.empty() && star.empty())
                    return false;
                if(!l.empty())
                    l.pop();
                else
                    star.pop();
            }
        }

        while(!l.empty() && ! star.empty())
        {
            if(l.top() > star.top())
                return false;
            l.pop();
            star.pop();
        }
        return l.empty();
    }
};