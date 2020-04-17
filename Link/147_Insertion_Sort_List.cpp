#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * dummyhead = new ListNode(0);
        ListNode * p = head;
        while(p != NULL){
            ListNode *next = p->next;
            ListNode *cur = dummyhead;
            while(cur->next && cur->next->val < p->val)
                cur = cur->next;
            p->next = cur->next;
            cur->next = p;
            p = next;
        }
        ListNode *retNode = dummyhead->next;
        delete dummyhead;
        return retNode;
    }
};