#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>> q;
        q.push(make_pair(n,0));
        vector<bool> visited(n+1,false);
        while(!q.empty())
        {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i=0;;i++){
                int a = num - i*i;
                if(a <0)
                    break;
                if(a==0)
                    return step+1;
                if(!visited[a]){
                    q.push(make_pair(a,step+1));
                    visited[a] = true;
                }
            }
        }
        throw invalid_argument("No Solution.");
    }
};

// class Solution {
// public:
//   int numSquares(int n) {
//     vector<int> dp(n + 1, INT_MAX >> 1);
//     dp[0] = 0;
//     for (int i = 1; i <= n; ++i)
//       for (int j = 1; j * j <= i; ++j) 
//         dp[i] = min(dp[i], dp[i - j * j] + 1);
//     return dp[n];
//   }
// };