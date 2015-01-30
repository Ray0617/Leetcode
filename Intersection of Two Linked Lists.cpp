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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // hard to implement in O(n) time and O(1) memory, so I take the reference from the discussion
        int sum = 0;
        ListNode* node = headA;
        while (node) {
            sum += node->val;
            node = node->next;
        }
        
        int count = 0;
        node = headB;
        while (node) {
            node->val ++;
            count++;
            node = node->next;
        }
        
        int sum2 = 0;
        node = headA;
        while (node) {
            sum2 += node->val;
            node = node->next;
        }
        
        int share_node = sum2 - sum;
        count -= share_node;
        node = headB;
        ListNode* ret = nullptr;
        while (node) {
            node->val --;   //restore
            if (count == 0) {
                ret = node;
            }
            count--;
            node = node->next;
        }
        return ret;
    }
};