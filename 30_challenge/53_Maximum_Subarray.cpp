#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int max = nums[0];
        if(nums.size()==1)
            return max;
        if(sum<0)
            sum =0;
        for (int i=1;i<nums.size();i++){
            sum += nums[i];
            if (sum>max)    // must keep this order, if put this judge below the sum<0, will meet problem, such as -1, -2
                max = sum;
            if(sum<0)
                sum =0;
        }
        return max;
    }
};