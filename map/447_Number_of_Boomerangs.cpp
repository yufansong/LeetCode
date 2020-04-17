#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        for(int i =0;i<points.size();i++){
            unordered_map<int,int> record;
            for(int j=0;j<points.size();j++)
                if(i!=j)
                    record[dis(points[i],points[j])]++;
            for(unordered_map<int,int>::iterator it=record.begin();it != record.end();it++)
                result += (it->second) * (it->second-1);
        }
        return result;
    }
private:
    int dis(vector<int> &pa, vector<int> &pb){
        return(pa[0] - pb[0]) *(pa[0] - pb[0]) + (pa[1] - pb[1]) *(pa[1] - pb[1]);
    }
};