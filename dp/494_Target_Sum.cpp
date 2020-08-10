#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i];
        if(sum < S)
            return 0;
        int offset = sum;
        vector<vector<int>> dp(n+1,vector<int>(sum+offset+1,0));
        dp[0][offset] = 1;
        for(int i=0;i<n;i++)
            for(int j=nums[i];j<offset + sum +1 - nums[i];j++){
                dp[i+1][j+nums[i]] += dp[i][j];
                dp[i+1][j-nums[i]] += dp[i][j];
            }
        return dp[n][S+offset];
    }
};