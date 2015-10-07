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
	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (start == end)
			return nullptr;
		int len = end - start;
		int left_len = len / 2;
		TreeNode* root = new TreeNode(nums[start + left_len]);
		root->left = sortedArrayToBST(nums, start, start + left_len);
		root->right = sortedArrayToBST(nums, start + left_len + 1, end);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size());
	}
};

