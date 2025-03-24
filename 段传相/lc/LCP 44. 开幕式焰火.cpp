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

    unordered_set<int> st;
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        st.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    int numColor(TreeNode* root) {
        dfs(root);
        return st.size();
    }
};