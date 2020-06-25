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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, long min_val, long max_val){
        if(!root)
            return true;
        if(root->val <= min_val || root->val >= max_val)
            return false;
        return isValidBST(root->left,min_val,root->val) && isValidBST(root->right,root->val,max_val);
    }
};