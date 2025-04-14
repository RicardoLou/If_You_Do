#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n, m;
    cin >> n >> m;
    vector<int> v1(n + 1), v2(m + 1);
    unordered_map<int, vector<int>> mp1, mp2;
    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> v2[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp1[a].push_back(b);
    }
    for (int i = 1; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mp2[a].push_back(b);
    }
    int ans = 0;
    auto&& dfs = [&](auto&& dfs, int a, int b, int cnt)->void {
        if (v1[a] != v2[b]) {
            return;
        }
        ans = max(ans, cnt + 1);
        for (int i = 0; i < mp1[a].size(); i++) {
            for (int j = 0; j < mp2[b].size(); j++) {
                dfs(dfs, mp1[a][i], mp2[b][j], cnt + 1);
            }
        }
        };
    dfs(dfs, 1, 1, 0);
    cout << ans;
    return 0;
}