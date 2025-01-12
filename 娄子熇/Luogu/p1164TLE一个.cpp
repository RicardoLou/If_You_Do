#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int p[N];
int n, m;
int ans = 0;

void dfs(int index, int sum) {
    if (sum == m) {
        ans ++;
        return;
    }
    if (sum > m || index > n) 
        return;
    // 枚举从当前菜品到最后的所有菜品
    for (int i = index; i < n; i++) {
        dfs(i + 1, sum + p[i]);
    }
    // 选或不选 dfs+DP
    // dfs(index + 1, sum);
    // dfs(index + 1, sum + p[index]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    dfs(0, 0);
    cout << ans;
}