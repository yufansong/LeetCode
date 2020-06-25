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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root)
            return res;
        if(!root->left && !root->right){
            if(root->val == sum){
                res.push_back(vector<int> (1,root->val));
                return res;
            }
            else            
                return res;
        }
        vector<vector<int>> leftV = pathSum(root->left,sum - root->val);
        vector<vector<int>> rightV = pathSum(root->right,sum - root->val);
        
        for(int i=0;i<leftV.size();i++){
            leftV[i].insert(leftV[i].begin(),root->val);
            res.push_back(leftV[i]);
        }
        for(int i=0;i<rightV.size();i++){
            rightV[i].insert(rightV[i].begin(),root->val);
            res.push_back(rightV[i]);
        }
        return res;
    }
};