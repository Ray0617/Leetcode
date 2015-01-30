/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode node = headA;
        int sumA = 0;
        while (node != null) {
            sumA += node.val;
            node = node.next;
        }
        
        int countB = 0;
        node = headB;
        while (node != null) {
            node.val++;
            countB++;
            node = node.next;
        }
        
        int sumA2 = 0;
        node = headA;
        while (node != null) {
            sumA2 += node.val;
            node = node.next;
        }
        int numSharedNote = sumA2 - sumA;
        countB -= numSharedNote;
        node = headB;
        ListNode ret = null;
        while (node != null) {
            node.val--; //restore
            if (countB-- == 0)
                ret = node;
            node = node.next;
        }
        return ret;
    }
}