#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
vector<vector<int> > a(N, vector<int>(N, 0));
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int max_x = 0, max_y = 0;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 可能出现前面大后面小的情况
        int x_start = min(x1, x2);
        int x_end = max(x1, x2);
        int y_start = min(y1, y2);
        int y_end = max(y1, y2);

        // 开区间差分
        a[x_start][y_start]++;
        a[x_start][y_end]--;
        a[x_end][y_start]--;
        a[x_end][y_end]++;

        max_x = max(max_x, x_end);
        max_y = max(max_y, y_end);
    }

    int ans = 0;
    // 计算二维前缀和
    for (int i = 0; i <= max_x; ++i) {
        for (int j = 0; j <= max_y; ++j) {
            if (i > 0)
                a[i][j] += a[i - 1][j];
            if (j > 0)
                a[i][j] += a[i][j - 1];
            if (i > 0 && j > 0)
                a[i][j] -= a[i - 1][j - 1];
            // 统计有效区域
            if (i < max_x && j < max_y && a[i][j] > 0)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}