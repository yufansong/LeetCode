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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* p=head;
        ListNode* tail;
        ListNode* retail;
        int length = 0;
        while(p){
            tail = p;
            p = p->next;
            length ++;
        }
        k = k % length;
        cout<<length<<" "<<k<<endl;
        if(k==0)
            return head;
        p = head;
        for(int i=0;i<length - k;i++){
            retail = p;
            p = p->next;
        }
        dummyhead->next = p;
        tail->next = head;
        retail->next = nullptr;
        ListNode* retNode = dummyhead->next;
        delete(dummyhead);
        return retNode;
    }
};