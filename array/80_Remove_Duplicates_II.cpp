#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        int length = 1;
        int remind = nums[0];
        bool flag = true;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == remind)
            {
                if (flag == true)
                {
                    flag = false;
                    nums[length++] = nums[i];
                }
            }
            else
            {
                flag = true;
                nums[length++] = nums[i];
                remind = nums[i];
            }
        return length;
    }
};