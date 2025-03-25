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
    bool isUnivalTree(TreeNode* root) {
        unordered_set<int> st;
        auto&& dfs = [&st](auto&& dfs, TreeNode* root)->void {
            if (root == nullptr) {
                return;
            }
            st.insert(root->val);
            if (st.size() > 1) {
                return;
            }
            dfs(dfs, root->left);
            dfs(dfs, root->right);
            };
        dfs(dfs, root);
        return st.size() <= 1;
    }
};