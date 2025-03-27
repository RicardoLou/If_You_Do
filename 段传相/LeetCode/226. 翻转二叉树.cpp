/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        auto&& dfs = [](auto&& dfs, TreeNode* node)->TreeNode* {
            if (node == nullptr) {
                return nullptr;
            }
            TreeNode* left = dfs(dfs, node->left);
            TreeNode* right = dfs(dfs, node->right);
            node->left = right;
            node->right = left;
            return node;
            };
        return dfs(dfs, root);
    }
};