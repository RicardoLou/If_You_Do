class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0, max = 0;
        auto&& dfs = [&](auto&& dfs, int i, int j)->void {
            if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j] != 1) {
                return;
            }
            grid[i][j] = 2;
            count++;
            dfs(dfs, i + 1, j);
            dfs(dfs, i - 1, j);
            dfs(dfs, i, j - 1);
            dfs(dfs, i, j + 1);
            };

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    count = 0;
                    dfs(dfs, i, j);
                    if (max < count) {
                        max = count;
                    }
                }
            }
        }
        return max;
    }
};