#include<string>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stack;
        for(int i=0;i<path.size();){
            while(i<path.size() && path[i] == '/')
                i++;
            string s = "";
            while(i<path.size() && path[i] != '/')
                s += path[i++];
            if(s==".." && !stack.empty())
                stack.pop();
            if(s!="" && s!="." && s!= "..")
                stack.push(s);
        }
        if(stack.empty())
            return "/";
        string s = "";
        while(!stack.empty()){
            s = '/'+stack.top() + s;
            stack.pop();
        }
        return s;
    }
};