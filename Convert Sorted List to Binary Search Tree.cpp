/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, ListNode*> sortedListToBST(ListNode* head, int n) {
        if (n == 0)
            return make_pair(nullptr, head);
        if (n == 1)
            return make_pair(new TreeNode(head->val), head->next);
        auto left = sortedListToBST(head, n / 2);
        TreeNode* root = new TreeNode(left.second->val);
        root->left = left.first;
        auto right = sortedListToBST(left.second->next, n - n / 2 - 1);
        root->right = right.first;
        return make_pair(root, right.second);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* node = head;
        while (node) {
            len++;
            node = node->next;
        }
        return sortedListToBST(head, len).first;
    }
};

