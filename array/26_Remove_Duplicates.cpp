#include<iostream>
#include<vector>
using namespace std;

/*
Need to pay attention to the input vector has 0 elements.
If input is 0 element, it will error.
Error: Char 9: runtime error: reference binding to null pointer of type 'const int'
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        if (nums.size()==0)
            return 0;
        for(int i = 0;i<nums.size();i++)
            if (length != i)
                if (nums[i] != nums[length])
                    nums[++length] = nums[i];
        
        return length+1;
    }
    
};