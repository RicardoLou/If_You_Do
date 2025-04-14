class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));//邻接矩阵
        for (auto x : times) {
            g[x[0] - 1][x[1] - 1] = x[2];
        }

        vector<int> dis(n, INT_MAX / 2);//最短路径长度
        vector<bool> f(n, false);//是否访问过
        dis[k - 1] = 0;

        while (1) {
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (!f[i] && (x < 0 || dis[i] < dis[x])) {
                    x = i;
                }
            }

            if (x < 0) {
                return ranges::max(dis);
            }
            if (dis[x] == INT_MAX / 2) {
                return -1;
            }
            f[x] = true;
            for (int i = 0; i < n; i++) {
                dis[i] = min(dis[i], dis[x] + g[x][i]);
            }

        }
    }
};