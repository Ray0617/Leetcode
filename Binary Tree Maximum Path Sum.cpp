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
private:
    int maxSumEndAt(TreeNode* root, int& result) {
        if (!root)
            return 0;
		int left = max(0, maxSumEndAt(root->left, result));
		int right = max(0, maxSumEndAt(root->right, result));
        int sum = root->val + max(left, right);
        if (root->val + left + right > result)
            result = root->val + left + right;
        return sum;
    }
public:
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        maxSumEndAt(root, result);
        return result;  
    }
};