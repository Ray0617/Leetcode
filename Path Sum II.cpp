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
    void pathSum(TreeNode* root, int target, vector<int>& path, vector<vector<int> >& result) {
        if (!root) 
            return;
        if (!root->left && !root->right && target == root->val) {
            path.push_back(root->val);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        pathSum(root->left, target - root->val, path, result);
        pathSum(root->right, target - root->val, path, result);
        path.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        pathSum(root, sum, path, result);
        return result;
    }
};