#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            vector<int> nums_part(nums.begin()+i+1,nums.end());
            vector<vector<int>> result_part = threeSum(nums_part,target-nums[i]);
            for(int j=0;j<result_part.size();j++){
                vector<int>item ({nums[i],result_part[j][0],result_part[j][1],result_part[j][2]});
                result.push_back(item);
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == target)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }
                else if (nums[i] + nums[j] + nums[k] < target)
                    j++;
                else if (nums[i] + nums[j] + nums[k] > target)
                    k--;
            }
        }
        return result;
    }
};