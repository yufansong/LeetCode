#include<vector>
#include<unordered_map>
using namespace std;

// Author: Huahua
class Solution {
public:
  void solve(vector<vector<char>>& board) {
    const int m = board.size();
    if (m == 0) return;
    const int n = board[0].size();    
    
    function<void(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || x >= n || y < 0 || y >= m || board[y][x] != 'O') return;
      board[y][x] = 'G'; // mark it as good      
      dfs(x - 1, y);
      dfs(x + 1, y);
      dfs(x, y - 1);
      dfs(x, y + 1);
    };
    
    for (int y = 0; y < m; ++y)
      dfs(0, y), dfs(n - 1, y);    
    
    for (int x = 0; x < n; ++x)
      dfs(x, 0), dfs(x, m - 1);    
    
    map<char, char> v{{'G','O'},{'O','X'}, {'X','X'}};
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        board[y][x] = v[board[y][x]];
  }
};