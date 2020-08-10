#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return n;
        vector<int> up (n,1);
        vector<int> down (n,1);
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j])
                    up[i] = max(up[i] , down[j] +1);
                if(nums[i] < nums[j])
                    down[i] = max(down[i], up[j]+1);
            }
        return max(down[n-1],up[n-1]);
    }
};