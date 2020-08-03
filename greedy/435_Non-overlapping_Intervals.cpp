#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res=0, last = 0;
        sort(intervals.begin(),intervals.end());
        // for(int i=0;i<intervals.size();i++)
        //     cout<<intervals[i][0]<<intervals[i][1]<<endl;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < intervals[last][1]){
                res++;
                if(intervals[i][1] < intervals[last][1])
                    last = i;
            }
            else
                last = i;
        }
        return res;
    }
};