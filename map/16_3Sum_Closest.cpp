#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int j = i+1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int gap1 = abs(target - (nums[i] + nums[j] + nums[k]));
                int gap2 = abs(target-result);
                if (gap1<gap2)
                    result = nums[i] + nums[j] + nums[k];
                if (nums[i] + nums[j] + nums[k] == target)
                {
                    return target;
                    j++;
                    k--;
                    while (j  < k && nums[j] == nums[j -1])
                        j++;
                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }
                else if (nums[i] + nums[j] + nums[k] < target){
                    j++;
                }
                    
                else if(nums[i] + nums[j] + nums[k] > target)
                    k--;
            }
        }
        return result;
    }
};