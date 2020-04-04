#include<iostream>
#include<vector>
#include<set>
using namespace std;

/*
pay attention to set
set.count(x): return the number of x in set
Must need to find the set, because the n maybe not in cycle

You can use Floyd algorithm, it is amazing
*/
class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        set<int> cycle;
        while(num != 1)
        {
            num = getnum(num);
            if(cycle.count(num) == 1)
                return false;
            cycle.insert(num);
        }
        return true;
    }

    int getnum(int n){
        int result = 0;
        while(n>0){
            result += (n%10)*(n%10);
            n /= 10;
        }
        return result;
    }
};