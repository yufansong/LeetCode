#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    static bool comp(pair<char,int> a, pair<char,int> b){
        if(a.second>b.second)
            return true;
        else
            return false;
    }
    string frequencySort(string s) {
        map<char,int> m;
        vector<pair<char,int>> v;
        string result;
        for(auto x:s){
            if(m.find(x) == m.end())
                m[x] = 0;
            m[x] ++;
        }
        for(map<char,int>::iterator it=m.begin();it!=m.end();it++)
            v.push_back(pair<char,int>((*it).first,(*it).second));
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++)
            for(int j=0;j<v[i].second;j++)
                result += v[i].first;
        return result;
    }
};