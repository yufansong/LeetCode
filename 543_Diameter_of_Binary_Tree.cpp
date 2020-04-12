#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int depth = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return depth;
    }
    int dfs(TreeNode *root){
        if(root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        depth = max(depth,left+right);
        return max(left,right) +1;
    }
};