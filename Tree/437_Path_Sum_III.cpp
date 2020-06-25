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
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        int res = 0;
        res += hasPathSum(root,sum);
        res += pathSum(root->left,sum);
        res += pathSum(root->right,sum);
        return res;
    }
private:
    int hasPathSum(TreeNode* root, int sum) {
        int res = 0;
        if(root == NULL)
            return 0;
        if(root->val == sum)
            res += 1;
        res += hasPathSum(root->left,sum - root->val);
        res += hasPathSum(root->right,sum - root->val);
        return res;
    }
};