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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> res;
        if(root == NULL)
            return result;
        queue<pair <TreeNode* , int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            TreeNode * node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(level == res.size())
                res.push_back(vector<int>());
            res[level].insert(res[level].begin(),node->val);
            if(node->left)
                q.push(make_pair(node->left,level+1));
            if(node->right)
                q.push(make_pair(node->right,level+1));
        }
        for(int i=0;i<res.size();i++)
            result.push_back(res[i][0]);
        return result;
    }
};