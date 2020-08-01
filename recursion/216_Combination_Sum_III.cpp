#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    void dfs(vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>&res,vector<bool> used,int start,int k){
        if(target<0 || k<0)
            return;
        if(k ==0){
            if(target == 0)
                res.push_back(cur);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>0 && candidates[i] == candidates[i-1] && !used[i-1] )
                continue;
            used[i] = true;
            k--;
            cur.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],cur,res,used,i+1,k);
            cur.pop_back();
            used[i] = false;
            k++;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates{1,2,3,4,5,6,7,8,9};
        sort(begin(candidates),end(candidates));
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool>used(candidates.size(),false);
        dfs(candidates,n,cur,res,used,0,k);
        return res;
    }
};