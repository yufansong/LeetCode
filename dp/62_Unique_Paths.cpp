class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<n)
            swap(m,n);
        int a = m+n-2;
        int b = n-1;
        double res = 1;
        for(int i=0;i<n-1;i++)
            res *= a--;
        for(int i=0;i<n-1;i++){
            res /= b--;
        }
            
        return res;
    }
};