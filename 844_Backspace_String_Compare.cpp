#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int j=T.size()-1;
        int i=S.size()-1;
        int countS=0;
        int countT=0;
        while(i>=0 || j>=0){
            while(i>=0 && (S[i]=='#' ||countS>0)){
                S[i] =='#' ? countS++ : countS--;
                i--;
            }
            while(j>=0 && (T[j]=='#' ||countT>0)){
                T[j] =='#' ? countT++ : countT--;
                j--;
            }
            if(i<0 || j<0)
                return i==j;
            if(S[i] == T[j])
            {
                i--;
                j--;
            }
            else
                return false;
        }
        return i==j;
    }
};