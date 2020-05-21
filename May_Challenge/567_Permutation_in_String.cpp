#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1>len2)
            return false;
        vector<int> map1(26),map2(26);
        for(int i=0;i<len1;i++){
            map1[s1[i] - 'a'] ++;
            map2[s2[i] - 'a'] ++;
        }
        if(map1 == map2)
            return true;
        
        for(int i=0;i+len1 <len2; i++){
            map2[s2[i] - 'a'] --;
            map2[s2[i+len1] - 'a'] ++;
            if(map1 == map2)
                return true;
        }
        return false;
    }
};