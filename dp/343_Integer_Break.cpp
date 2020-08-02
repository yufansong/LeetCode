#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n+1,-1);
        memo[0] = 0;
        memo[1] = 1;

        for(int i=2;i<=n;i++)
            for(int j=1; j<=i-1;j++)
                memo[i] = max(memo[i], max(j*(i-j) , j* memo[i-j]));
        return memo[n];
    }
};