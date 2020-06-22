#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1;i>=0;i--)
            s.push(nestedList[i]);
    }
    
    int next() {
        NestedInteger t = s.top();
        s.pop();
        return t.getInteger();
    }
    
    bool hasNext() {
        while(!s.empty()){
            NestedInteger t = s.top();
            if(t.isInteger())
                return true;
            s.pop();
            const vector<NestedInteger> v = t.getList();
            for(int i= v.size()-1;i>=0;i--)
                s.push(v[i]);
        }
        return false;
    }
private:
    stack<NestedInteger> s;
};
