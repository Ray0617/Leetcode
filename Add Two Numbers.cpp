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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == 0)
            return l2;
        ListNode* head = 0;
        ListNode* node = 0;
        bool carry = false;
        while (l1 || l2 || carry)
        {
            int digit = carry;
            if (l2 != 0)
            {
                digit += l2->val;
                l2 = l2->next;
            }
            if (l1 != 0)
            {
                digit += l1->val;
                l1 = l1->next;
            }
            carry = digit >= 10;
            digit %= 10;
            if (node)
            {
                node->next = new ListNode(digit);
                node = node->next;
            }
            else
            {
                node = new ListNode(digit);
                head = node;
            }
        }
        return head;
    }
};