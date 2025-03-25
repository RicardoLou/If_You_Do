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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> v;
        int index = 0;
        auto&& dfs = [&v, &index, voyage](auto&& dfs, TreeNode* root)->void {
            if (root == nullptr) {
                return;
            }
            if (root->val != voyage[index++]) {
                v.clear();
                v.push_back(-1);
                return;
            }
            if (index < voyage.size() && root->left != nullptr && root->left->val != voyage[index]) {
                v.push_back(root->val);
                dfs(dfs, root->right);
                dfs(dfs, root->left);
            }
            else {
                dfs(dfs, root->left);
                dfs(dfs, root->right);
            }
            };
        dfs(dfs, root);
        if (v.size() != 0 && v[0] == -1) {
            v.clear();
            v.push_back(-1);
        }
        return v;
    }
};