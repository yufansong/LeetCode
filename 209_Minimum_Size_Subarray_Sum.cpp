#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l=0, r=-1;
        int length = nums.size()+1;
        int sum = 0;
        while(l<nums.size()){
            if(sum<s && r+1<nums.size()){
                r++;
                sum+=nums[r];
            }
            else{
                sum -= nums[l];
                l++;
            }
            if(sum>=s)
                length = min(length,r-l+1);
        }
        if (length == nums.size()+1)
            return 0;
        return length;

    }
};