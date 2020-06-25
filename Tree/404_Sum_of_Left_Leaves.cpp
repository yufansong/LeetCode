#include<iostream>
#include<queue>
#include<vector>

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left && !root->left->left && !root->left->right)
            return sumOfLeftLeaves(root->right) + root->left->val;
        return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
    }
};