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
    public ListNode partition(ListNode head, int x) {
        ListNode lHead = null;
        ListNode lTail = null;
        ListNode geHead = null;
        ListNode geTail = null;
        ListNode node = head;
        while (node != null) {
            if (node.val < x) {
                if (lHead == null) {
                    lHead = lTail = node;
                }
                else {
                    lTail.next = node;
                    lTail = node;
                }
            }
            else {
                if (geHead == null) {
                    geHead = geTail = node;
                }
                else {
                    geTail.next = node;
                    geTail = node;
                }
            }
            ListNode cutTail = node;
            node = node.next;
            cutTail.next = null;
        }
        if (lHead == null)
            return geHead;
        lTail.next = geHead;
        return lHead;
    }
}