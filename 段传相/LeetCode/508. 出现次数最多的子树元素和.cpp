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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> v;
        int max = 0;
        auto&& dfs = [&mp, &max](auto&& dfs, TreeNode* root)->int {
            if (root == nullptr) {
                return 0;
            }
            int sum = root->val + dfs(dfs, root->left) + dfs(dfs, root->right);
            max = std::max(max, ++mp[sum]);
            return sum;
            };
        dfs(dfs, root);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == maxa) {
                v.emplace_back(it->first);
                //emplace_back直接在容器末尾构造新对象，避免了中间的临时对象和拷贝/移动操作。
            }
        }
        return  v;
    }
};