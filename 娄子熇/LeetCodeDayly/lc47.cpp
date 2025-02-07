#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> ans;
    
    void dfs(int u, vector<bool>& vis, vector<int>& path, vector<int>& nums) {
        if (u == nums.size()) {
            ans.insert(path);  // 当路径长度达到 nums.size() 时，将路径加入结果集
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;  // 如果第 i 个元素已经被选择过，跳过
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;  // 因为已经排序过了 所以可以根据相邻来判断重复
            
            vis[i] = true;  // 标记当前元素为已使用
            path[u] = nums[i];  // 将当前元素添加到路径中
            
            dfs(u + 1, vis, path, nums);  // 递归处理下一个元素
            
            vis[i] = false;  // 回溯，标记当前元素为未使用
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 排序，确保重复的元素被正确处理
        
        int n = nums.size();
        vector<bool> vis(15, false);  // vis 数组，用于标记元素是否已经使用
        vector<int> path(n);  // 存储当前排列的路径
        
        dfs(0, vis, path, nums);  // 调用递归函数
        
        return vector<vector<int>>(ans.begin(), ans.end());  // 将 set 转换为 vector 返回
    }
};
