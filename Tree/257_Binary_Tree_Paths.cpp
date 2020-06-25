#include<iostream>
#include<queue>
#include<vector>
#include<string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root ==NULL)
            return res;
        if(!root->left && !root->right){
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> leftS = binaryTreePaths(root->left);
        vector<string> rightS = binaryTreePaths(root->right);
        for(int i=0;i<leftS.size();i++)
            res.push_back(to_string(root->val)+"->"+leftS[i]);
        for(int i=0;i<rightS.size();i++)
            res.push_back(to_string(root->val)+"->"+rightS[i]);
        return res;
    }
};