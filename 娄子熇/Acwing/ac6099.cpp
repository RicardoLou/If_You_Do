#include<bits/stdc++.h>
using namespace std;

const int N  = 100010;
vector<int> relation[N];
bool vis[N], st[4];
int path[4];
int n;
int ans[N];

int get(int begin, int a, int b, int c) {
    for(int t : relation[begin]) {
        // 找到那一个未知的
        if (t != a && t != b && t != c) {
            return t;
        }
    }
    return -1;
}
// 找出当前一种排列方式的关系是否正确
bool check() {
    ans[2] = 1; // 起始点
    int d[] = {0, 1, 3, 4};
    // 当前一种排列
    for(int i = 0; i < 4; i ++) {
        ans[d[i]] = relation[1][path[i]];
    }
    for(int i = 5; i < n + 5; i ++) {
        // 从已有的开始推一个未知的，可以得到三个关系，剩下一个就一定是未知的
        ans[i] = get(ans[i - 2], ans[i - 1], ans[i - 3], ans[i - 4]);
        if (ans[i] == -1) return false;
    }
    for(int i = 0; i < 5; i ++) {
        if (ans[i] != ans[n + i])
            return false;
    }
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i ++) {
        int t = ans[i];
        if (vis[t]) return false;
        vis[t] = true;
    }
    for(int i = 0; i < n; i ++) {
        printf("%d ", ans[i]);
    }
    return true;
}

bool dfs(int u) {
    if (u == 4) {
        return check();
    }
    for(int i = 0; i < 4; i ++) {
        if (!st[i]) {
            st[i] = true;
            path[u] = i;
            if (dfs(u + 1)) return true;
            st[i] = false;
        }
    }
    return false;
}
int main() {
    cin >> n;
    for(int i = 0; i < n * 2; i ++) {
        int x, y;
        cin >> x >> y;
        relation[x].push_back(y);
        relation[y].push_back(x);
    }
    if (!dfs(0)) puts("-1");
    return 0;
}