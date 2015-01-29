/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
            return;
        List<ListNode> stack = new ArrayList<ListNode>();
        ListNode node = head;
        while (node != null) {
            stack.add(node);
            node = node.next;
        }
        int len = stack.size();
        for (int i = 0; i < len; i++) {
            if (i < len / 2)
                stack.get(i).next = stack.get(len - 1 - i);
            else
                stack.get(i).next = stack.get(len - i); // i > 0 => len >= 2
        }
        stack.get(len / 2).next = null;
    }
}