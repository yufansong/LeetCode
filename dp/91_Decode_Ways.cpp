#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        if(s.length() == 1)
            return 1;
        vector<int> dp(s.length()+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=s.length();i++){
            if(!isValid(s[i-1]) && !isValid(s[i-2],s[i-1]))
                return 0;
            if(isValid(s[i-1]))
                dp[i] += dp[i-1];
            if(isValid(s[i-2],s[i-1]))
                dp[i] += dp[i-2];
        }
        return dp[s.length()];
    }
private:
    bool isValid(const char c){
        return c!='0';
    }
    bool isValid(const char c1, const char c2){
        const int num = (c1 - '0')*10 + (c2 -'0');
        return num>=10 && num <=26;
    }
};