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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return null;
        int val = head.val - 1;
        ListNode node = head;
        head = null;        
        ListNode prev = null;
        while (node != null) {
            if (node.val == val || (node.next != null && node.val == node.next.val)) {
                // this node should be removed
                val = node.val;
                if (prev != null)
                    prev.next = node.next;
            }
            else {
                // this node is unique
                prev = node;
                if (head == null)
                    head = node;
            }
            node = node.next;
        }
        return head;
    }
}