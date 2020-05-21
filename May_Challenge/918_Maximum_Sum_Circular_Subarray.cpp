#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.empty())
            return 0;
        int total = 0, Max = A[0],curmax=0,Min=A[0],curmin=0;
        for(int i=0;i<A.size();i++){
            total += A[i];
            curmax = max(A[i],A[i]+curmax);
            curmin = min(A[i],A[i]+curmin);
            Max = max(Max,curmax);
            Min = min(Min,curmin);
        }
        return Max<0? Max:max(Max, total-Min);
    }
};