#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2)
            return 0;
        vector<int> minPrice(n,0);
        vector<int> maxProfit(n,0);
        minPrice[0] = prices[0];
        maxProfit[0] = 0;
        for(int i=1;i<n;i++){
            minPrice[i] = min(minPrice[i-1],prices[i]);
            maxProfit[i] = max(maxProfit[i-1],prices[i] - minPrice[i-1]);
        }
        return maxProfit[n-1];
    }
};