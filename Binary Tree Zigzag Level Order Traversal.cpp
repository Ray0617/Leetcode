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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (root == 0)
            return ret;
        
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        bool left_to_right = true;
        while (!nodes.empty()) {
            vector<int> val;
            if (left_to_right)
                for (unsigned i = 0; i < nodes.size(); i++)
                    val.push_back(nodes[i]->val);
            else
                for (int i = (int)nodes.size() - 1; i >= 0; i--)
                    val.push_back(nodes[i]->val);
            ret.push_back(val);
            
            left_to_right = !left_to_right;
            vector<TreeNode*> prev_level = nodes;
            nodes.clear();
            for (unsigned i = 0; i < prev_level.size(); i++) {
                if (prev_level[i]->left)
                    nodes.push_back(prev_level[i]->left);
                if (prev_level[i]->right)
                    nodes.push_back(prev_level[i]->right);
            }
        }
        return ret;
    }
};