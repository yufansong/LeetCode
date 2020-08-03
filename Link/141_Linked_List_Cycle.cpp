/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast) {
            if (!fast->next) 
                return false;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) 
                return true;
        }
        return false;
    }
};

// class Solution {
// public:
//   bool hasCycle(ListNode *head) {
//     unordered_set<ListNode*> seen;
//     while (head) {
//       if (seen.count(head)) return true;
//       seen.insert(head);
//       head = head->next;
//     }
//     return false;
//   }
// };