#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> large(nums.size(),0) ,small(nums.size(),0);
        large[0] = nums[0];
        small[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            large[i] = max(large[i-1]*nums[i],max(small[i-1]* nums[i], nums[i]));
            small[i] = min(large[i-1]*nums[i],min(small[i-1]* nums[i], nums[i]));
        }
        return *max_element(large.begin(),large.end());
    }
};