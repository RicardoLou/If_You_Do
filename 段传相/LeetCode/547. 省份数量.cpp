class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> f(n, false);
        auto&& dfs = [isConnected, n, &f](auto&& dfs, int i)->void {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && f[j] == 0) {
                    f[j] = true;
                    dfs(dfs, j);
                }
            }
            return;
            };
        for (int i = 0; i < n; i++) {
            if (f[i] == false) {
                dfs(dfs, i);
                count++;
            }
        }
        return count;
    }
};