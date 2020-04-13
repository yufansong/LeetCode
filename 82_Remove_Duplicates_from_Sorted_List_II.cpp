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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode * dummyHead1 = new ListNode(head->val-2);
        ListNode * dummyHead2 = new ListNode(head->val-1);
        dummyHead1->next = dummyHead2;
        dummyHead2->next = head;
        ListNode * pre = dummyHead1, * cur = dummyHead2;
        int val = pre->val;
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                ListNode * delNode = cur;
                val = cur->val;
                pre->next = cur->next;
                cur = cur->next;
                delete delNode;
            }
            else if(cur->val == val){
                ListNode * delNode = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete delNode;
            }
            else{
                val = cur->val;
                pre = cur;
                cur = cur->next;
                
            }
        }
        ListNode * retNode = dummyHead1->next->next;
        delete dummyHead1;
        delete dummyHead2;
        return retNode;
    }
};