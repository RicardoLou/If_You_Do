#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100; // 最大维度
int R, C;
int grid[MAXN][MAXN]; // 存储高度
int dp[MAXN][MAXN];   // 记忆化数组
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // 四个方向

// DFS + 记忆化搜索
int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y]; // 如果已经计算过，直接返回
    dp[x][y] = 1; // 初始化为 1，表示当前点本身

    // 遍历四个方向
    for (int k = 0; k < 4; ++k) {
        int nx = x + dir[k][0];
        int ny = y + dir[k][1];

        // 判断是否在范围内，并且高度递减
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] < grid[x][y]) {
            dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny)); // 递归计算并更新 dp
        }
    }

    return dp[x][y];
}

int main() {
    // 输入行列
    cin >> R >> C;

    // 初始化 grid 和 dp
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
            dp[i][j] = -1; // 初始状态为 -1
        }
    }

    int max_length = 0;

    // 遍历每个点，求最长路径
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            max_length = max(max_length, dfs(i, j)); // 更新全局最长路径
        }
    }

    cout << max_length << endl; // 输出结果
    return 0;
}