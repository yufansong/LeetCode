#include<vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>&b,int x,int y,int h,vector<vector<bool>>& v){
        if( x<0 || y<0 || x==b.size() || y==b[0].size())
            return;
        if(v[x][y]  || b[x][y]<h)
            return ;
        v[x][y] = true;
        dfs(b,x+1,y,b[x][y],v);
        dfs(b,x-1,y,b[x][y],v);
        dfs(b,x,y+1,b[x][y],v);
        dfs(b,x,y-1,b[x][y],v);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<bool>> p(m,vector<bool>(n,false));
        vector<vector<bool>> a(m,vector<bool>(n,false));
        for(int x=0;x<m;x++){
            dfs(matrix,x,0,0,p);
            dfs(matrix,x,n-1,0,a);
        }
        for(int y=0;y<n;y++){
            dfs(matrix,0,y,0,p);
            dfs(matrix,m-1,y,0,a);
        }
        vector<vector<int>> res;
        for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
             if(p[i][j] && a[i][j])
                res.push_back(vector<int>{i,j});
        return res;
    }
};