#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        // if use following denode code, may cause overflow
        // return to_string(stoi(num1)+stoi(num2));
        if(num1.length() < num2.length())
            swap(num1,num2);
        num1 = "0" + num1;
        int l1 = num1.length();
        int l2 = num2.length();
        int count = 0;
        for(int i=1;i<=l2;i++){
            int a = (num1[l1-i] - '0' )+ (num2[l2-i] - '0') + count;
            count = a/10;
            num1[l1-i] = a%10 + '0';
        }
        int i=l2+1;
        while(count){
            int a = (num1[l1-i] - '0' ) + count;
            count = a/10;
            num1[l1-i] = a%10 + '0';
            i++;
        }
        return num1[0] == '0' ? &num1[1] : num1;
    }
};