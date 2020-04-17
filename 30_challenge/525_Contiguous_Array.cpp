#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int& i : nums)
            if(i ==0)
                i = -1;
        m.insert({0,-1});
        int sums = 0, result = 0;
        for(int i=0;i<nums.size();i++){
            sums += nums[i];
            if(m.count(sums))
                result = max(result,i-m[sums]);
            else
                m.insert({sums,i});
        }
        return result;
    }
};