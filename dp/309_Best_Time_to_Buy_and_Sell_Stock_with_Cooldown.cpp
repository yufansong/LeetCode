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
        buy[1] = max(0-prices[1],buy[0]);
        sell[1] = max(sell[0],buy[0] + prices[1]);
        for(int i=2;i<n;i++){
            buy[i] = max(buy[i-1],sell[i-2] - prices[i]);
            sell[i] = max(sell[i-1],buy[i-1] + prices[i]);
        }
        return sell[n-1];
        
        
        // int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        // for (int price : prices) {
        //     pre_buy = buy;
        //     buy = max(pre_sell - price, pre_buy);
        //     pre_sell = sell;
        //     sell = max(pre_buy + price, pre_sell);
        //     cout<<buy<<" "<<sell<<endl;
        // }
        // return sell;
    }
};