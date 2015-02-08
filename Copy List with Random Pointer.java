/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        //n1->n2->n3->... => n1->c1->n2->c2->n3->c3->...
        RandomListNode node = head;
        while (node != null) {
            RandomListNode clone = new RandomListNode(node.label);
            clone.next = node.next;
            node.next = clone;
            node = clone.next;
        }
        
        //ni-[random]->nj => ci-[random]->cj
        node = head;
        while (node != null) {
            if (node.random != null) {
                RandomListNode clone = node.next;
                RandomListNode clonerandom = node.random.next;
                clone.random = clonerandom;
            }
            node = node.next.next;
        }
        
        if (head == null)
            return null;
        node = head;
        RandomListNode clonehead = head.next;
        RandomListNode clone = clonehead;
        while (node != null) {
            node.next = clone.next;
            if (clone.next != null)
                clone.next = clone.next.next;
            node = node.next;
            clone = clone.next;
        }
        return clonehead;
    }
}