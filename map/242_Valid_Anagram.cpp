#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size())
            return false;
        map <char,int> record;
        for(int i =0;i<s.size();i++){
            record[s[i]] ++;
        }
        for(int i =0;i<t.size();i++){
            if(record[t[i]])
                record[t[i]]--;
            else
                return false;

        }
        return true;
    }
};