#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sum = 0;
        
        for(int i =0;i<shift.size();i++){
            if(shift[i][0] == 1)
                sum += shift[i][1];
            else
                sum -= shift[i][1];
        }
        while(sum<0)
            sum += s.size();
        while(sum>= s.size())
            sum -= s.size();
        string result = "";
        for(int i=s.size() - sum ;i<s.size();i++){
            result += s[i];
        }
        for(int i=0;i<s.size() - sum;i++)
            result += s[i];
            
        return result;
    }
};
    }
};