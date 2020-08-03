class Solution {
public:
    int minDistance(string word1, string word2) {
                int l1 = word1.length();
        int l2 = word2.length();
        // d[i][j] := minDistance(word1[0:i - 1], word2[0:j - 1]);
        vector<vector<int>> d(l1 + 1, vector<int>(l2 + 1, 0));
        
        for (int i = 0; i <= l1; ++i)
            d[i][0] = i;
        for (int j = 0; j <= l2; ++j)
            d[0][j] = j;
        
        for (int i = 1; i <= l1; ++i)
            for (int j = 1; j <= l2; ++j) {
                int c = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                d[i][j] = min(d[i - 1][j - 1] + c, 
                              min(d[i][j - 1], d[i - 1][j]) + 1);
            }
        
        return d[l1][l2];
    }
};