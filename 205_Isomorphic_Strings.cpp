#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mapC;
        for(int i=0;i<s.length();i++){
            for(auto x:mapC){
                if(x.first == s[i] && x.second!=t[i])
                    return false;
                if(x.first != s[i] && x.second==t[i])
                    return false;
            }
        mapC[s[i]] = t[i]; 
        }
        return true;
    }
};