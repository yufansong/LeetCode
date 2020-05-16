#include <iostream>
#include <vector>
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
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if(preorder.empty())
            return nullptr;
        int n = preorder.size();
        return reduce(preorder,0,n);
    }
    TreeNode * reduce(vector<int> & preorder, int start, int end){
        if(start>= end)
            return nullptr;
        int i= start +1;
        for(; i <end && preorder[i]< preorder[start];i++)
            ;
        TreeNode * root = new TreeNode(preorder[start]);
        root->left = reduce(preorder,start+1,i);
        root->right = reduce(preorder,i,end);
        return root;
    }
};