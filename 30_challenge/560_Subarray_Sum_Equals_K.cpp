#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result =0, sum=0, n=nums.size();
        unordered_map<int, int> m{{0,1}};
        for(int i=0;i<n;i++){
            sum+= nums[i];
            result+=m[sum-k];
            m[sum]++;
        }
        return result;
    }
};