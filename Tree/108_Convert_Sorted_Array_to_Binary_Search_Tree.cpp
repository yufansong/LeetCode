#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
        if(high < low)
            return NULL;
        int mid = low + (high - low) /2;
        TreeNode * root = new TreeNode (nums[mid]);
        root->left = sortedArrayToBST(nums,low,mid-1);
        root->right = sortedArrayToBST(nums,mid +1, high);
        return root;
    }
};