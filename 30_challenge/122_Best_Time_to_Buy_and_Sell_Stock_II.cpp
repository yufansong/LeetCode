#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size()<2)
            return 0;
        for(int i =0;i<prices.size();){
            int sell = i;
            while(sell+1<prices.size() && prices[sell+1]>prices[sell])
                sell++;
            if(prices[sell]-prices[i]>0){
                profit+= prices[sell] - prices[i];
                i = sell+1;
            }
            else
                i++;
        }
        return profit;
    }
};