#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int countSquares(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int count = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= n; j++) {
        if (i != 0 && j != 0 && matrix[i - 1][j - 1] == 1)
          dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        count += dp[i][j];
      }

    return count;
  }
};