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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return ;
        ListNode * p=head, *q=head;
        while(q->next && q->next->next){
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = nullptr;
        ListNode *pre=nullptr, *cur=q, *next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        q = pre;
        p = head;
        while(p && q){
            pre = p;
            next = q;
            p = p->next;
            q = q->next;
            pre->next = next;
            next->next = p;
        }
        return ;
    }
};