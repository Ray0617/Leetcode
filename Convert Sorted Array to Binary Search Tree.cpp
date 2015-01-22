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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty())
            return 0;
        
        int mid_pos = num.size() / 2;        
        vector<int> left(mid_pos);
        int* ptr = &num[0];
        copy(ptr, ptr + mid_pos, left.begin());
        int mid = num[mid_pos];
        vector<int> right(num.size() - 1 - mid_pos);
        copy(ptr + mid_pos + 1, ptr + num.size(), right.begin());
        TreeNode* root = new TreeNode(mid);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
