#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        row = grid.size();
        col = grid[0].size();
        for(int i=0;i<row;i++)
            for(int j =0;j<col;j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    result++;
                    dfs(grid,i,j);
                }
            }
        return result;
    }
private:
    int direction[5] = {0,1,0,-1,0};
    int result = 0,row,col;
    void dfs(vector<vector<char>>& grid, int x, int y){
        for(int i=0;i<4;i++){
            int nx=x+direction[i];
            int ny=y+direction[i+1];
            if(0<=nx && nx<row && 0<=ny && ny<col && grid[nx][ny] =='1' ){
                grid[nx][ny] = '0';
                dfs(grid,nx,ny);
            }
        }
    }
};