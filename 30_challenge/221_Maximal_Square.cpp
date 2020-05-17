#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
          if(matrix.empty()) return 0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[i].size();j++)
            {
                dp[i][j] = matrix[i][j] - '0';
            }
        }
        
        int Max = 0;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[i].size();j++)
            {
                if(dp[i][j] && i-1 >=0 && j-1>=0)
                {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                
                }
                // cout<<dp[i][j];
                Max = max(Max,dp[i][j]);
            }
            // cout<<endl;
        }
        return Max*Max;
    }
};