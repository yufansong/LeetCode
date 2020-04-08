#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record(nums.begin(),nums.end());
        if(record.size()!=nums.size())
            return true;
        else
            return false;
    }
};