#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        for(int i=0;i<size2;i++){
            nums1[size1-i-1] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};