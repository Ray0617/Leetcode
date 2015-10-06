/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        TreeLinkNode* pre_level = root;
        while (pre_level->left) {
            TreeLinkNode* pre_node = pre_level;
            TreeLinkNode superhead(0);
            TreeLinkNode* node = &superhead;
            while (pre_node) {
                node->next = pre_node->left;
                node = node->next;
                node->next = pre_node->right;
                node = node->next;
                pre_node = pre_node->next;
            }
            pre_level = pre_level->left;
        }
    }
};

