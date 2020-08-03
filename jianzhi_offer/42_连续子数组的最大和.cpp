class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int length = array.size();
        if(length == 0)
            return 0;

        int sum = 0;
        int maxSum = array[0];
        for(int i=0; i<length; ++i){
            sum += array[i];
            if(maxSum < sum)
                maxSum = sum;
            if(sum < 0)
                sum = 0;
        }

        return maxSum;
    }
};