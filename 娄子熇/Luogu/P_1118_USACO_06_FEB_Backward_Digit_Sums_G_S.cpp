#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int n, sum;
int path[N];
int vis[N];
bool found = false;
void dfs(int u) {
    if (found)
        return;
    if (u == n) {
        int temp[N];
        copy(path, path + n, temp);
        for (int t = n - 1; t > 0; t--) {
            for (int i = 0; i < t; i++) {
                temp[i] += temp[i + 1];
            }
        }
        if (temp[0] == sum) {
            for (int i = 0; i < n; i++) {
                cout << path[i] << (i == n - 1 ? "\n" : " ");
            }
            found = true;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            path[u] = i;

            int partial_sum = 0;
            for (int j = 0; j <= u; j++) {
                partial_sum += path[j];
            }

            if (partial_sum <= sum) { // 剪枝
                dfs(u + 1);
            }

            vis[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> sum;
    dfs(0);
    return 0;
}