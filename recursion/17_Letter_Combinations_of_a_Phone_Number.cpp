#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    const string letterMap[10]={
        " ",    //0
        "",     //1
        "abc",     //2
        "def",     //3
        "ghi",     //4
        "jkl",     //5
        "mno",     //6
        "pqrs",     //7
        "tuv",     //8
        "wxyz"     //9
    };
    vector<string> res;
    void findCombination(const string &digits, int index, const string &s){
        if(index == digits.size()){
            res.push_back(s);
            return;
        }
            
        char c = digits[index];
        assert(c>='0' && c<='9' && c!='1');
        string letters = letterMap[c-'0'];
        for(int i=0;i<letters.size();i++)
            findCombination(digits,index+1,s+letters[i]);
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() ==0)
            return res;
        res.clear();
        findCombination(digits,0,"");
        return res;
    }
};