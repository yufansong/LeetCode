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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        vector<string> res = sumString(root);
        int sum = 0;
        for(int i=0;i<res.size();i++)
            sum += stoi(res[i]);
        return sum;
    }
    vector<string> sumString(TreeNode* root){
        vector<string> res;
        if(!root->left && !root->right){
            res.push_back(to_string(root->val));
            return res;
        }
        if(root->left){
            vector<string> leftS = sumString(root->left);
            for(int i=0;i<leftS.size();i++)
                res.push_back(to_string(root->val)+leftS[i]);
        }
        if(root->right){
            vector<string> rightS = sumString(root->right);
            for(int i=0;i<rightS.size();i++)
                res.push_back(to_string(root->val)+rightS[i]);
        }
        return res;
    }
};