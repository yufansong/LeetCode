#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        int freqT[256] = {0};
        int count = 0;
        int minlen = INT_MAX;
        string res = "";
        for(int i = 0;i<t.size();i++){
            freqT[t[i]] ++;
        }
        while(r<s.size()){
            if(--freqT[s[r]]>=0){
                count++;
            }
            while(count==t.size()){
                if(minlen>r-l+1){
                    minlen = r-l+1;
                    res = s.substr(l,minlen);
                }
                if(++freqT[s[l]]>0)
                    count--;
                l++;
            }
            r++;
        }
        return res;
    }
};