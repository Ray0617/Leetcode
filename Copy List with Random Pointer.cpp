/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode* node = head;
        while (node != 0) {
            RandomListNode* clone = new RandomListNode(node->label);
            m[node] = clone;
            node = node->next;
        }
        node = head;
        while (node != 0) {
            if (node->random)
                m[node]->random = m[node->random];
            if (node->next)
                m[node]->next = m[node->next];
            node = node->next;
        }
        return m[head];
    }
};