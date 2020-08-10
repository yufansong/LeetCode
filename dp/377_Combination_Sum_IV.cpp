#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1,0); //some test case may have large target, if use int, will overflow
        dp[0] = 1;
        for(int i=1;i<=target;i++)
            for(int num : nums)
                if(i-num >=0)
                    dp[i] += dp[i-num];
        return int(dp[target]);
    }
};