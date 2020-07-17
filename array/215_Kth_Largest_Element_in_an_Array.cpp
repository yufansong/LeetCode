#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums,0,nums.size()-1,k);
    }

    int quick_sort(vector<int>& nums, int left,int right,int k){
        int i = left;
        int j = left;
        int pivot = nums[right];
        int len = right - left +1;
        if (left<right){
            for (;j<right;j++)
                if(nums[j]>pivot){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                }
            nums[j] = nums[i];
            nums[i] = pivot;
        
            int which_max = i-left +1;
            if (which_max == k)
                return pivot;
            else if(which_max<k)
                return quick_sort(nums,i+1,right,k-which_max);
            else
                return quick_sort(nums,left,i-1,k);    
        }
        else
            return pivot;
    }
};