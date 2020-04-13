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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * dummyNode = new ListNode(0);
        ListNode * p1 = l1,*p2 = l2, *cur = dummyNode;
        while(p1 && p2){
            if(p1->val < p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(p1)
            cur->next = p1;
        if(p2)
            cur->next = p2;
        ListNode * retNode = dummyNode->next;
        delete dummyNode;
        return retNode;
    }
};