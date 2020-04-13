#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *begin = NULL;
        ListNode *cur = head;
        if(head->next == NULL || m==n)
            return head;
        for (int i = 1; i < m; i++)
        {
            if(cur!= NULL){
                begin = cur;
                cur = cur->next;
            }
            
        }
        ListNode *pre = NULL;
        for (int i = m - 1; i < n; i++)
        {
            if(cur!= NULL){
                ListNode *next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
        }
        if(begin)
        {
            begin->next->next = cur;
            begin->next = pre;    
            return head;
        }
        else
        {
            head->next = cur;
            return pre;
        }
        return head;
    }
};