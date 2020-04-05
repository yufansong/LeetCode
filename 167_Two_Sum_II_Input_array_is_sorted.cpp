#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size()<2)
            return vector<int>{1};
        int left = 0;
        int right = numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                int result[2] = {left+1,right+1};
                return vector<int>(result,result+2);
            }
            else if (numbers[left]+numbers[right]<target)
                left ++;
            else
                right --;
        }
        return vector<int>{0};
    }
};