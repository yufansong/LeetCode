#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        if(points.size()==0)
            return 0;
        for(int i=0;i<points.size();i++){
            int inf = 0;
            int same = 0;
            int result = 0;
            map<pair<int,int>,int> slopes;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0] == points[j][0] && points[i][1] != points[j][1]){
                    inf ++;
                    if (result<inf)
                        result = inf;
                }
                else if((points[i][0] == points[j][0] && points[i][1] == points[j][1])){
                    same ++;
                }
                else {
                    int a = points[j][0] - points[i][0];
                    int b = points[j][1] - points[i][1];
                    int gcd = GCD(a, b);
                    a /= gcd; b /= gcd;
                    slopes[make_pair(a, b)]++;
                    if(result<slopes[make_pair(a, b)])
                        result = slopes[make_pair(a, b)];
                }
            }
            res = max(result+same,res);
        }
        return res+1;
    }
private:
    int GCD(int a, int b) 
    {      
        if(b == 0) return a;
        else return GCD(b, a % b);
    }
};