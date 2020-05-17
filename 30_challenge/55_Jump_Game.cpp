#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int maxreach = 0;
        for(int i=0;i!=N;i++){
            if(i>maxreach)
                return false;
            maxreach = max(maxreach, i+nums[i]);
            if (maxreach >= N-1)
                return true;
        }
        return false;
    }
};