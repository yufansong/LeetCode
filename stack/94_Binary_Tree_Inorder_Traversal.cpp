#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define CMD1 "go"
#define CMD2 "print"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Command{
    string s;
    TreeNode * node;
    Command(string s, TreeNode * node): s(s), node(node) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Command> stack;
        stack.push(Command(CMD1,root));
        while(!stack.empty()){
            Command cmd = stack.top();
            stack.pop();
            if(cmd.s == CMD2)
                res.push_back(cmd.node->val);
            else{
                if(cmd.node->right)
                    stack.push(Command(CMD1,cmd.node->right));
                stack.push(Command(CMD2,cmd.node));
                if(cmd.node->left)
                    stack.push(Command(CMD1,cmd.node->left));
            }
        }
        return res;
    }
};