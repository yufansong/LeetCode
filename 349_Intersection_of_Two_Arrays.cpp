#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record;
        set<int> resultSet;
        vector<int> resultVector;
        for(int i =0;i<nums1.size();i++)
            record.insert(nums1[i]);
        for(int i =0;i<nums2.size();i++)
            if(record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);
        for(set<int>::iterator iter=resultSet.begin();iter!= resultSet.end();iter++)
            resultVector.push_back(*iter);
        return resultVector;
    }
};