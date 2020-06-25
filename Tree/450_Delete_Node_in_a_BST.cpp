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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val < key)
            root->right =  deleteNode(root->right,key);
        else if(root->val > key)
            root->left =  deleteNode(root->left,key);
        else{
            if(root->left && root->right){
                TreeNode * min = root->right;
                while(min->left)
                    min = min->left;
                root->val = min->val;
                root->right = deleteNode(root->right,min->val);
            }
            else{
                TreeNode * new_root = root->left == NULL ? root->right : root->left;
                root->left = root->right = NULL;
                delete root;
                return new_root;
            }
        }
        return root;
    }
};