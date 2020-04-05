#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        int i =0;
        int j = s.length()-1;
        while(i<j){
            while(i<j && !isalnum(s[i]))
                i++;
            while(i<j && !isalnum(s[j]))
                j--;
            if(i<j && tolower(s[i])!= tolower(s[j]))
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};