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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast)
                return 0;
            fast = fast->next;
            if (slow == fast) {
                // circle detect
                ListNode* node = head;
                while (node != slow) {
                    node = node->next;
                    slow = slow->next;
                }
                return node;
            }
        }
        return 0;
    }
};