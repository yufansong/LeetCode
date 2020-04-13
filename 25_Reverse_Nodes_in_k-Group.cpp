#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int count = 0;
        ListNode *dummyhead = new ListNode(0), *cur = head, *pre = dummyhead;
        pre = dummyhead;
        pre->next = NULL;

        while (count < k && cur != NULL)
        {
            dummyhead = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = dummyhead;
            count++;
        }
        if (cur != NULL)
            head->next = reverseKGroup(cur, count);
        if (k != count)
            return reverseKGroup(pre->next, count);
        return pre->next;
    }
};