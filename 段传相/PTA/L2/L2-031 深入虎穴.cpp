#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<int> f(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            v[i].push_back(y);
            f[y] = 1;//标记不是出口的
        }
    }

    int maxcnt = -1, idx;
    auto&& dfs = [&](auto&& dfs, int jd, int cnt)->void {
        if (v[jd].size() == 0) {
            if (maxcnt < cnt) {
                idx = jd;
                maxcnt = cnt;
            }
            return;
        }

        for (int i = 0; i < v[jd].size(); i++) {
            dfs(dfs, v[jd][i], cnt + 1);
        }
        return;
        };

    int s = 0;
    while (f[++s]);//找入口
    dfs(dfs, s, 0);

    cout << idx;

}