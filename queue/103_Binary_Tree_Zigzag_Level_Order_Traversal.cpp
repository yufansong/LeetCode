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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<pair <TreeNode* , int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            TreeNode * node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level == res.size())
                res.push_back(vector<int>());
            if( level %2 ==0)
                res[level].push_back(node->val);
            else
                res[level].insert(res[level].begin(), node->val);
            if(node->left)
                q.push(make_pair(node->left,level+1));
            if(node->right)
                q.push(make_pair(node->right,level+1));
        }
        return res;
    }
};