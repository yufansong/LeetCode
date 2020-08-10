#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2 != 0)
            return false;
        int n = nums.size();
        int C = sum/2;
        vector<bool> dp(C+1, false);
        for(int i=0;i<=C;i++)
            dp[i] = (nums[0] == i);
        for(int i=1;i<n;i++)
            for(int j=C;j>=nums[i];j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        return dp[C];
    }
};