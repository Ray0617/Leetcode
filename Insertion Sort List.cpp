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
    ListNode* insertionSortList(ListNode* head) {
        ListNode superhead(0);
        ListNode* pending = head;
        while (pending) {
            ListNode* node = pending;
            pending = pending->next;
            node->next = nullptr;
            ListNode* prev = &superhead;
            ListNode* now = prev->next;
            while (now && now->val < node->val) {
                prev = prev->next;
                now = now->next;
            }
            prev->next = node;
            node->next = now;
        }
        return superhead.next;
    }
};

