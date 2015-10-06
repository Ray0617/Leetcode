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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode superhead(0);
        ListNode* tail = &superhead;
        ListNode* check = head;
        while (check) {
            ListNode* node = check;
            int count = 0;
            while (node && node->val == check->val) {
                count++;
                node = node->next;
            }
            if (count == 1) {
                tail->next = check;
                tail = check;
            }
            check = node;
        }
        tail->next = nullptr;
        return superhead.next;
    }
};

