#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
    void dfs(vector<int> nums, vector<int> &cur, int start, int n){
        if(n ==0){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<nums.size();i++){
            cur.push_back(nums[i]);
            dfs(nums,cur,i+1,n-1);
            cur.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        used = vector<bool> (res.size(),false);
        vector<int> cur;
        for(int i=0;i<=nums.size();i++)
            dfs(nums,cur,0,i);
        return res;
    }
};