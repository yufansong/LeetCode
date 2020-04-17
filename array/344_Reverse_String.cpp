#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i =0, j=s.size()-1;
        for(;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
};