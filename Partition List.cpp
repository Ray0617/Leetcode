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
    ListNode *partition(ListNode *head, int x) {
        ListNode* lhead = 0;
        ListNode* lnode = 0;
        ListNode* gehead = 0;
        ListNode* genode = 0;
        ListNode* node = head;
        while (node) {
            if (node->val < x) {
                if (!lhead) {
                    lhead = node;
                    lnode = node;
                }
                else {
                    lnode->next = node;
                    lnode = lnode->next;
                }
            }
            else {
                if (!gehead) {
                    gehead = node;
                    genode = node;
                }
                else {
                    genode->next = node;
                    genode = genode->next;
                }
            }
            node = node->next;
        }
        if (!lhead)
            return gehead;
        lnode->next = gehead;
        if (genode)
            genode->next = 0;
        return lhead;
    }
};