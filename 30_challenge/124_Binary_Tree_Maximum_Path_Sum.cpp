#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int maxpath = INT_MIN;
public:
    int maxPathSum(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        path(root);
        return maxpath;
    }
    int path(TreeNode *node){
        if(node == NULL)
            return 0;
        int left = max(path(node->left),0);
        int right = max(path(node->right),0);
        maxpath = max(maxpath,left+right+node->val);
        return max(left+node->val,right+node->val);
    }
};