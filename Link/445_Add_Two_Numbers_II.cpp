#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode head(0);
        ListNode *cur = &head;
        int extra = 0;
        while(l1 || l2 || extra){
            int sum = (l1? l1->val : 0) + (l2 ? l2-> val : 0) + extra;
            extra = sum /10;
            l1 = l1?l1->next: NULL;
            l2 = l2?l2->next: NULL;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
        }
        cur = reverse(head.next);
        return cur;
    }
private:
    ListNode* reverse(ListNode* head){
        ListNode * pre = NULL;
        ListNode * cur = head;
        if(cur == NULL) 
            return head;
        while(cur!= NULL){
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};