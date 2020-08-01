#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    void dfs(vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>&res,vector<bool> used,int start){
        if(target<0)
            return;
        if(target == 0){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>0 && candidates[i] == candidates[i-1] && !used[i-1] )
                continue;
            used[i] = true;
            cur.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],cur,res,used,i+1);
            cur.pop_back();
            used[i] = false;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool>used(candidates.size(),false);
        dfs(candidates,target,cur,res,used,0);
        return res;
    }
};