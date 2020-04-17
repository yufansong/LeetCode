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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode * p = dummyhead, *q = dummyhead;
        for(int i=0;i<n+1;i++)
            q = q->next;
        while(q!=NULL){
            p = p->next;
            q = q->next;
        }
        ListNode * delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode * retNode = dummyhead->next;
        delete dummyhead;
        return retNode;
    }
};