#include<vector>
using namespace std;

class Solution {
private:
    void dfs(vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>&res,int start){
        if(target<0)
            return;
        if(target == 0){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            cur.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],cur,res,i);
            cur.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates,target,cur,res,0);
        return res;

    }
};