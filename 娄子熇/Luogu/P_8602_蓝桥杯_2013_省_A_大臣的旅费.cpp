#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n;
int maxDis = -1; // 第一遍dfs最大值
int maxNode = -1; // 第一遍dfs最远的点
struct Edge {
    int to, weight;
};
bool vis[N];
vector<Edge> g[N];

void dfs(int node, int dis) {
    vis[node] = true;
    // 记录最远点
    if (dis > maxDis) {
        maxDis = dis;
        maxNode = node;
    }
    for(const auto &x : g[node]) {
        if (!vis[x.to]) {
            dfs(x.to, dis + x.weight);
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    memset(vis, false, sizeof(vis));
    dfs(1, 0);
    int a = maxNode;

    memset(vis, false, sizeof(vis));
    maxDis = -1;
    // 从A点出发找到最远点 就是树的最远直径
    dfs(a, 0);
    int ans = maxDis * 10 + maxDis * (maxDis + 1) / 2;
    cout << ans << endl;
    return 0;
}