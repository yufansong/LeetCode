#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2)
            return 0;
        vector<int> buy(n,0);
        vector<int> sell(n,0);
        
        buy[0] = -prices[0];
        sell[0] = 0;
        for(int i=1;i<n;i++){
            buy[i] = max(buy[i-1],sell[i-1] - prices[i]);
            sell[i] = max(sell[i-1],buy[i-1] + prices[i]);
        }
        return sell[n-1];
  
    }
};
