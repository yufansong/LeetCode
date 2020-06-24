#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        auto myCmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode*>,decltype(myCmp)> q(myCmp);
        for(ListNode* list : lists)
            if(list)
                q.push(list);
        while(!q.empty()){
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if(cur->next)
                q.push(cur->next);
        }
        return dummy.next;
    }


};