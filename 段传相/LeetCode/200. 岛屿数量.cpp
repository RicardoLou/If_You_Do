class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        auto&& dfs = [&count, &grid](auto&& dfs, int x, int y)->void {
            if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size() || grid[y][x] != '1') {
                return;
            }
            if (grid[y][x] == '1') {
                grid[y][x] = '2';
            }
            dfs(dfs, x + 1, y);
            dfs(dfs, x - 1, y);
            dfs(dfs, x, y - 1);
            dfs(dfs, x, y + 1);
            };

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(dfs, j, i);
                }
            }
        }
        return count;
    }
};