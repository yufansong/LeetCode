#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int> result(nums.size(),1);
         for(int i=0;i<nums.size()-1;i++){
             result[i+1] = result[i] * nums[i];
         }
         int right = 1;
         for(int i=nums.size()-1;i>=0;i--){
             result[i] *= right;
             right *= nums[i];
         }
         return result;
    }
};