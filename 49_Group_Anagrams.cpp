#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,vector<string>> mapRes;
        for(int i =0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(mapRes.find(s)==mapRes.end()){
                vector<string> item;
                mapRes[s] = item;
            }
            mapRes[s].push_back(strs[i]);
        }
        for(map<string,vector<string>>::iterator it=mapRes.begin();it!=mapRes.end();it++){
            result.push_back((*it).second);
        }
        return result;
    }
};