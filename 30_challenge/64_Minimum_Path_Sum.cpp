#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0; i--){
            dp[m-1][i] = grid[m-1][i] + dp[m-1][i+1];
        }
        for(int j=m-1;j>=0;j--){
            dp[j][n-1] = grid[j][n-1] + dp[j+1][n-1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = grid[i][j] + min(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};