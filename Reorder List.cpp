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
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return;
        vector<ListNode*> stack;
        ListNode* node = head;
        while (node != nullptr) {
            stack.push_back(node);
            node = node->next;
        }
        for (unsigned i = 0; i < stack.size(); i++) {
            if (i < stack.size() / 2)
                stack[i]->next = stack[stack.size() - 1 - i];
            else
                stack[i]->next = stack[stack.size() - i];
        }
        stack[stack.size()/2]->next = nullptr;
    }
};