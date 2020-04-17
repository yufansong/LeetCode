#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        int result = 0;
        map<int,int> mapNum;
        for(int i=0;i<arr.size();i++){
            if(mapNum.find(arr[i]-1) == mapNum.end())
                mapNum[arr[i]-1] =0;
            mapNum[arr[i]-1] ++;
            }
        for(int i=0;i<arr.size();i++){
               if(mapNum.find(arr[i]) != mapNum.end() && mapNum[arr[i]]> 0){
                result ++;
            }
        }
        return result;
    }
};