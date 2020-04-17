#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// the overflow of the string will not report!  s+100 will not report error, so need to focus on line 21, cannot use: else if(freq[s[r+1]]==1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=-1;
        int length = 0;
        int freq[256] = {0};
        if(s.length()<2){
            return s.length();
        }
        while(l<s.length()){
            if(freq[s[r+1]]==0 && r+1<s.length()){
                r++;
                freq[s[r]]++ ;
            }
            else{
                freq[s[l]]--;
                l++;
            }
            length = max(length,r-l+1);
        }
        return length;
    }
};