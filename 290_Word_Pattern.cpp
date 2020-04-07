#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        map<char, string> m;
        vector<string> s;
        for (int i = 0; i < str.size(); i++)
        {
            int j = str.find(" ", i);
            string sub = str.substr(i, j - i);
            s.push_back(sub);
            if (j == -1)
            {
                break;
            }
            i = j;
        }
        int pn = pattern.size();
        int sn = s.size();
        if (pn != sn)
            return false;
        for (int i = 0; i < pn; i++)
        {
            for (auto x : m)
            {
                if (x.first == pattern[i] && x.second != s[i])
                {
                    return false;
                }
                if (x.first != pattern[i] && x.second == s[i])
                {
                    return false;
                }
            }
            m[pattern[i]] = s[i];
        }
        return true;
    }
};