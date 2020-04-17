#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int complement = target-nums[i];
            if(m.find(complement) != m.end()){
                int result[2] = {i,m[complement]};
                return vector<int>(result,result+2);
            }
            m[nums[i]] = i;
        }
        return vector<int>(0);
    }
};