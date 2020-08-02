#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si=0,ti=0;
        while(ti<t.size()&&si<s.size()){
            if(s[si] == t[ti]){
                si++;
                ti++;
            }
            else
                ti++;
        }
        return si == s.size();
    }
};