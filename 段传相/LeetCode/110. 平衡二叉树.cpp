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
    bool isBalanced(TreeNode* root) {
        auto&& dfs = [root](auto&& dfs, TreeNode* node)->int {
            if (node == nullptr) {
                return 0;
            }
            else {
                return max(dfs(dfs, node->left), dfs(dfs, node->right)) + 1;
            }
            };
        if (root == nullptr) {
            return true;
        }
        else {
            return abs(dfs(dfs, root->left) - dfs(dfs, root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};