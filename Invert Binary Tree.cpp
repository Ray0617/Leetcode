class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root)
			return nullptr;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		root->left = invertTree(right);
		root->right = invertTree(left);
		return root;
	}
};

