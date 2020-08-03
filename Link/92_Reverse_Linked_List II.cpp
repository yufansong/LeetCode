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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int m, int n) {
//         ListNode dummy(0);
//         dummy.next = head;
//         ListNode* p = &dummy;
//         // Find the m-1 th node
//         for (int i = 0; i < m - 1; ++i) 
//           p = p->next;
//         ListNode* prev = p;
//         ListNode* curr = p->next;
//         ListNode* tail = curr;    
//         // Reverse from m to n
//         for (int i = m; i <= n; ++i) {
//           ListNode* next = curr->next;
//           curr->next = prev;
//           prev = curr;
//           curr = next;
//         }    
//         //  Connect three parts
//         p->next = prev;
//         tail->next = curr;
//         return dummy.next;
//     }
// };