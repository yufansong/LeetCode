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
        ListNode *cur = head, *pre = NULL, *next;

        while (count < k && cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            count++;
        }
        if (cur != NULL)
            head->next = reverseKGroup(cur, count);
        if (k != count)
            return reverseKGroup(pre, count);
        return pre;
    }
};