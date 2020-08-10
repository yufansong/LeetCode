#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2)
            return 0;
        int k=2;
        vector<vector<int>> local(n,vector<int>(k+1,0));
        vector<vector<int>> global(n,vector<int>(k+1,0));
        for(int i=1;i<n;i++){
            int diff = prices[i] - prices[i-1];
            for(int j=1;j<=k;j++){
                local[i][j] = max(global[i-1][j-1] + max(diff,0), local[i-1][j] + diff);
                global[i][j] = max(global[i-1][j],local[i][j]);
            }
        }
        return global[n-1][k];
    }
};