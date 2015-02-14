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
    ListNode *deleteDuplicates(ListNode *head) {
        // prev -> node -> next
        if (!head)
            return 0;
        int pre_val = head->val - 1;
        ListNode* node = head;
        head = 0;
        ListNode* prev = 0;
        while (node) {
            if (node->val != pre_val && (!node->next || node->next->val != node->val)) {
                // this is an unique node
                if (!head)
                    head = node;
                prev = node;
                node = node->next;
            }
            else {
                // this node should be removed
                pre_val = node->val;
                if (prev) {
                    prev->next = node->next;
                }
                node = node->next;
            }
        }
        return head;
    }
};