#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.length();
        for (; i < j;)
        {
            if (isaeiou(s[i]) && isaeiou(s[j]))
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            while (!isaeiou(s[i]) && i<j)
                i++;
            while (!isaeiou(s[j]) && i<j)
                j--;
        }
        return s;
    }
    bool isaeiou(char c)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else
            return false;
    }
};