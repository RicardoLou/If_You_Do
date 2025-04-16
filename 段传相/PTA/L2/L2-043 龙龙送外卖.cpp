#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), d(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int sum = 0;
    auto&& dfs = [&](auto&& dfs, int jd)->int {
        if (v[jd] == -1 || d[jd] != 0) {
            return d[jd];
        }
        sum++;
        d[jd] = dfs(dfs, v[jd]) + 1;
        return d[jd];
        };

    int mx = -1;
    while (m--) {
        int x;
        cin >> x;
        mx = max(dfs(dfs, x), mx);
        cout << 2 * sum - mx << endl;
    }

}