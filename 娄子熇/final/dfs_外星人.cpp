#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, m, cnt = 0;
int a[N];
int path[N];
bool flag = false;
bool return0 = false;
bool st[N];
void dfs(int u) {
    if (return0) {
        return;
    }
    if (u > n) {
        flag = true;
        cnt ++;
        if (cnt == m + 1) {
            return0 = true;
            for(int i = 0; i < n; i ++) {
                cout << path[i] << " ";
            }
        }
        return;
    }

    for(int i = 1; i <= n; i ++) {
        if (!flag) {
            i = a[u];
        }
        if (!st[i]) {
            st[i] = true;
            path[u] = i;
            dfs(u + 1);
            st[i] = false;
            path[u] = 0; // 恢复现场，但其实这一步不需要，后续会覆盖掉
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
    }
    // 1、直接用next_permutation枚举m次即可
    // for (int i = 1; i <= m; ++i)
    // {

    //     next_permutation(a + 1, a + n + 1);
    // }
    dfs(0);
    // for (int j = 1; j <= n; ++j)
    //     printf("%d ", a[j]); // 输出格式注意
    return 0;
}