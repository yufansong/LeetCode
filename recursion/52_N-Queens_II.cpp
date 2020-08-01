#include<vector>
using namespace std;

class Solution {
private:
    int res;
    vector<bool> col,dia1,dia2;
    void putQueen(int n,int index){
        if(index==n){
            res++;
            return;
        }
        for(int i=0;i<n;i++)
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]){
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                putQueen(n,index+1);
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
            }
        return ;
    }
public:
    int totalNQueens(int n)  {
        res = 0;
        col = vector<bool>(n,false);
        dia1 = vector<bool>(2*n-1,false);
        dia2 = vector<bool>(2*n-1,false);
        putQueen(n,0);
        return res;
    }
};