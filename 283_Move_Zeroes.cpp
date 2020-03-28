#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        vector<int> nonZoreElements;
        for (int i =0; i<nums.size();i++)
            if(nums[i])
                nonZoreElements.push_back(nums[i]);
        for (int i=0;i<nonZoreElements.size();i++)
            nums[i] = nonZoreElements[i];
        
        for( int i = nonZoreElements.size();i<nums.size();i++)
            nums[i] = 0;
    }
};

// int main() {
//     int arr[] = {0,1,0,3,12};
//     vector<int> vec(arr,arr+sizeof(arr)/sizeof(int));
//     Solution().moveZeroes(vec);
//     for (int i=0;i<vec.size();i++)
//         cout<<vec[i]<<" ";
//     cout<<endl;
//     return 0;
// }