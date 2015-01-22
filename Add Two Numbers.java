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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ret = null;
        ListNode node = null;
        int carry = 0;
        while (l1 != null || l2 != null || carry > 0) {
            if (node == null) {
                ret = new ListNode(0);
                node = ret;
            }
            else {
                node.next = new ListNode(0);
                node = node.next;
            }
            int val1 = 0;
            if (l1 != null)
            {
                val1 = l1.val;
                l1 = l1.next;
            }
            int val2 = 0;
            if (l2 != null)
            {
                val2 = l2.val;
                l2 = l2.next;
            }
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            node.val = digit;
        }
        return ret;
    }
}