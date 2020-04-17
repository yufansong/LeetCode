#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> record;
        int result = 0;
        for(int i=0;i<C.size();i++)
            for(int j=0;j<D.size();j++)
                record[C[i] + D[j]] ++;
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
                if(record.find(0-A[i]-B[j]) != record.end())
                    result += record[0-A[i]-B[j]];
        return result;
    }
};