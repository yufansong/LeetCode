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
    bool isBalanced(TreeNode* root) {
        int left = 0, right = 0;
        if(!root)
            return true;
        left = height(root->left);
        right = height(root->right);
        return (abs(left-right)<=1) && isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }
};