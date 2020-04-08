#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *result= head;
        ListNode *p = head;
        while(1){
            if(p->next == NULL ){
                return result;
            }
            else if(p->next->next==NULL){
                return result->next;
            }
            else{
                p = p->next->next;
                result = result->next;
            }

        }
        return NULL;
    }
};