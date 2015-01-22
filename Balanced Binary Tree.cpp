/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node){
        if (node == 0)
            return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
    
    bool isBalanced(TreeNode *root) {
        if (root == 0)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
    }
};