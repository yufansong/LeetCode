#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if(board.size()==0) return false;
        h = board.size();
        w = board[0].size();
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++)
                if(search(board, word, 0, i, j)) return true;
        return false;
    }
    
    bool search(vector<vector<char>> &board, 
             const string& word, int d, int x, int y) {
        if(x<0 || x==w || y<0 || y==h || word[d] != board[y][x]) 
            return false;
        
        // Found the last char of the word
        if(d==word.length()-1)
            return true;
        
        char cur = board[y][x];
        board[y][x] = 0; 
        bool found = search(board, word, d+1, x+1, y)
                  || search(board, word, d+1, x-1, y)
                  || search(board, word, d+1, x, y+1)
                  || search(board, word, d+1, x, y-1);
        board[y][x] = cur;
        return found;
    }
private:
    int w;
    int h;
};



// class Solution {
// private:
//     int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
//     int m,n;
//     vector<vector<bool>> visited;
//     bool inArea(int x, int y){
//         return x>=0 && x<m && y>=0 && y<n;
//     }
//     bool searchWord(const vector<vector<char>> &board, const string & word, int index, int startx, int starty){
//         if(index == word.size()-1)
//             return board[startx][starty] == word[index];
//         if(board[startx][starty] == word[index]){
//             visited[startx][starty] = true;
//             for(int i=0;i<4;i++){
//                 int newx = startx + d[i][0];
//                 int newy = starty + d[i][1];
//                 if(inArea(newx,newy) && !visited[newx][newy] && searchWord(board,word,index+1,newx,newy))
//                     return true;
//             }
//             visited[startx][starty] = false;
//         }
//         return false;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         m = board.size();
//         assert(m>0);
//         n = board[0].size();
//         visited = vector<vector<bool>> (m, vector<bool>(n,false));

//         for(int i=0; i<board.size(); i++)
//             for(int j=0;i<board[i].size();j++)
//                 if(searchWord(board,word,0,i,j))
//                     return true;
//         return false;
//     }
// };