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
    int maxDepth(TreeNode* root) {
        int num = 0;
        auto&& dfs = [](auto&& dfs, TreeNode* root)->int {
            if (root == nullptr) {
                return 0;
            }
            return max(dfs(dfs, root->left), dfs(dfs, root->right)) + 1;
            };
        return num = dfs(dfs, root);
    }
};