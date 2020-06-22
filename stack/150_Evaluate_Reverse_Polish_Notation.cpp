#include <cctype>
#include <string>
#include <stack>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" &&tokens[i] != "*" &&tokens[i] != "/" )
                s.push(stoi(tokens[i]));
            else{
                int n2 = s.top();
                s.pop();
                int n1 = s.top();
                s.pop();
                int n = 0;
                switch (tokens[i][0])
                {
                case '+':
                    n = n1+n2;
                    break;
                case '-':
                    n = n1-n2;
                    break;
                case '*':
                    n = n1*n2;
                    break;
                case '/':
                    n = n1/n2;
                    break;
                default:
                    break;
                }
                s.push(n);
            }
        }
        return s.top();
    }
};