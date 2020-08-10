#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
class Solution {
private:
    unordered_map<TreeNode*, int> mt;
    unordered_map<TreeNode*, int> mf;
    int robtree(TreeNode* root, bool r){
        if(!root)
            return 0;
        if(r && mt.count(root))
            return mt[root];
        if(!r && mf.count(root))
            return mf[root];
        int res = 0,left0=0, left1=0,right0=0,right1=0;
        if(r){
            left0 = robtree(root->left,false);
            right0 = robtree(root->right,false);
            res = max(res,root->val + left0 + right0);
        }
        left1 = robtree(root->left,true);
        right1 = robtree(root->right,true);
        res = max(res, left1+right1);
        if(r)
            mt[root] = res;
        if(!r)
            mf[root] = res;
        return res;
    }
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        return max(robtree(root,true), robtree(root,false));
    }
};