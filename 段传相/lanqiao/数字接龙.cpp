#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, k;
    cin >> n >> k;
    vector<vector<int>> vv(n, vector<int>(n)), f(n, vector<int>(n, 0));
    int nxp[] = { -1,-1,0,1,1,1,0,-1 };//八向偏移
    int nyp[] = { 0,1,1,1,0,-1,-1,-1 };
    int djx[11][11][11][11] = {};//两点间连线，防止交叉
    string path = "";
    for (auto& x : vv) {
        for (int& y : x) {
            cin >> y;
        }
    }

    auto&& dfs = [&](auto&& dfs, int x, int y)->int {
        if (x == n - 1 && y == n - 1) {
            return path.length() == n * n - 1;
        }
        f[x][y] = 1;
        for (int i = 0; i < 8; i++) {
            int nx = x + nxp[i], ny = y + nyp[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            if (f[nx][ny] == 1) {
                continue;
            }
            if (vv[nx][ny] != (vv[x][y] + 1) % k) {
                continue;
            }
            if ((i % 2 != 0) && (djx[x][ny][nx][y] || djx[nx][y][x][ny])) {
                continue;
            }
            djx[x][y][nx][ny] = 1;
            path += i + '0';
            if (dfs(dfs, nx, ny) == 1) {
                return 1;
            }
            djx[x][y][nx][ny] = 0;
            path.pop_back();
        }
        f[x][y] = 0;//回溯
        return 0;
        };

    if (dfs(dfs, 0, 0) == 1) {
        cout << path;
    }
    else {
        cout << -1;
    }

    return 0;
}