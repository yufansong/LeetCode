#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        stack<TreeNode *> s;
        while(!s.empty() || root){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                s.pop();
                result.push_back(root->val);
                if(result.size()>=k)
                    break;
                root = root->right;
            }
        }
        return result[k-1];
    }
};