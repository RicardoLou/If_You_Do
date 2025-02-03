#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
vector<int> g[N];
queue<int> q;
vector<int> path;
int ind[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        ind[y] ++;
        g[x].push_back(y);
    }

    for(int i = 1; i <= n; i ++) {
        if (ind[i] == 0)
            q.push(i);
    }
    // 拓扑排序
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        // 入度为0的可以直接加入进来
        path.push_back(t);
        for(int j : g[t]) {
            -- ind[j];
            if (ind[j] == 0)
                q.push(j);
        }
    }
    // 走到最后了
    if (path.size() == n) {
        for(int i = 0; i < n; i ++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}