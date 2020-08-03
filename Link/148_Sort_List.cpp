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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *midnext = slow->next;
        slow->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(midnext);
        return mergeTwoLists(l1,l2);
    }
private:
    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2){
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode * dummyhead = new ListNode(-1);
        ListNode * p = dummyhead;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2= l2->next;
            }
            p = p->next;
            // p->next = NULL;
        }
        if(l1)
            p->next = l1;
        if(l2)
            p->next = l2;
        ListNode * retNode = dummyhead->next;
        delete dummyhead;
        return retNode;
    }
};


// Quick Sort Link
// struct Node 
// {
// 	int key;
// 	Node* next;
// 	Node(int nKey, Node* pNext)
// 		: key(nKey)
// 		, next(pNext)
// 	{}
// };
 
 
// Node* GetPartion(Node* pBegin, Node* pEnd)
// {
// 	int key = pBegin->key;
// 	Node* p = pBegin;
// 	Node* q = p->next;
 
// 	while(q != pEnd)
// 	{
// 		if(q->key < key)
// 		{
// 			p = p->next;
// 			swap(p->key,q->key);
// 		}
 
// 		q = q->next;
// 	}
// 	swap(p->key,pBegin->key);
// 	return p;
// }
 
// void QuickSort(Node* pBeign, Node* pEnd)
// {
// 	if(pBeign != pEnd)
// 	{
// 		Node* partion = GetPartion(pBeign,pEnd);
// 		QuickSort(pBeign,partion);
// 		QuickSort(partion->next,pEnd);
// 	}
// }