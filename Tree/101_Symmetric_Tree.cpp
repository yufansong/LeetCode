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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode* p1, TreeNode* p2){
        if(!p1 && !p2)
            return true;
        if(!p1 || !p2)
            return false;
        if(p1->val != p2->val)
            return false;
        return isMirror(p1->left,p2->right) && isMirror(p2->left,p1->right);
    }
};