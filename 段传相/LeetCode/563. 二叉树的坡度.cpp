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
    int findTilt(TreeNode* root) {
        int sum = 0;
        auto&& dfs = [&sum](auto&& dfs, TreeNode* root)->int {
            if (root == nullptr) {
                return 0;
            }
            int sl = dfs(dfs, root->left);
            int sr = dfs(dfs, root->right);
            sum += abs(sl - sr);
            return sl + sr + root->val;
            };
        dfs(dfs, root);
        return sum;
    }
};