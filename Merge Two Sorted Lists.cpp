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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == 0)
            return l2;
        if (l2 == 0)
            return l1;
            
        ListNode* ret;
        if (l1->val < l2->val)
        {
            ret = l1;
        }
        else
        {
            ret = l2;
        }

        ListNode head(0);
        ListNode* end = &head;
        while (l1 || l2)
        {
            if (l1 == 0)
            {
                end->next = l2;
                return head.next;
            }
            if (l2 == 0)
            {
                end->next = l1;
                return head.next;
            }
            
            if (l1->val < l2->val)
            {
                end->next = l1;
                l1 = l1->next;
            }
            else
            {
                end->next = l2;
                l2 = l2->next;
            }
            end = end->next;
        }
    }
};
