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
        TreeLinkNode* prevLevel = root;
        TreeLinkNode* thisLevel = root->left;
        while (thisLevel) {
            TreeLinkNode* prev = 0;
            TreeLinkNode* node = prevLevel;
            while (node) {
                if (node->left) {
                    if (prev) {
                        prev->next = node->left;
                    }
                    prev = node->left;
                    if (node->right) {
                        prev->next = node->right;
                        prev = node->right;
                    }
                }
                node = node->next;
            }
            prevLevel = thisLevel;
            thisLevel = thisLevel->left;
        }
    }
};