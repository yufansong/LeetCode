#include<stack>
using namespace std;

class StockSpanner {
private:
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    int next(int price) {
        int result = 1;
        while(!s.empty() && s.top().first<=price){
            result+=s.top().second;
            s.pop();
        }
        s.push({price,result});
        return result;
    }
};