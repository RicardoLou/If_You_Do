#include <bits/stdc++.h>
using namespace std;

const int N = 190;
int n, m;
bool g[N][N];
int ans[N][N];

// 左上右下
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void bfs() {
    queue<pair<int, int> > q;

    // 初始化 BFS 起点
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) {
                q.push(make_pair(i, j));  // 将所有标记点作为起点加入队列
                ans[i][j] = 0;   // 标记点的最短距离为 0
            } else {
                ans[i][j] = INT_MAX;  // 未标记点初始化为无穷大
            }
        }
    }

    // BFS 遍历
    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        int x = t.first, y = t.second;

        // 遍历当前点的四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 判断点是否在矩阵范围内，以及是否已经访问过
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                // 如果找到更短路径，更新并加入队列
                if (ans[nx][ny] > ans[x][y] + 1) {
                    ans[nx][ny] = ans[x][y] + 1;  // 更新到 nx, ny 的最短距离
                    q.push(make_pair(nx, ny));  // 加入队列，继续扩展
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j] - '0';
        }
    }

    bfs();  // 执行 BFS

    // 输出结果矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}