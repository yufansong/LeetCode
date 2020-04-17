#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j =height.size()-1;
        int m = 0;
        for(;i<j;){
            m = max(m,(j-i)*min(height[i],height[j]));
            if(height[i]<=height[j])
                i++;
            else if(height[i]>height[j])            
                j--;
        }
        return m;
    }
};