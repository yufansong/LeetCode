#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;
        int two = nums.size();
        for(int i =0;i<two;)
        {
            if (nums[i] == 1)
                i++;
            else if (nums[i]==2)
                swap(nums[i],nums[--two]);
            else
                swap(nums[++zero],nums[i++]);
        }
    }
}; 
