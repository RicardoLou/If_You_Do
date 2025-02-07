#include<bits/stdc++.h>
using namespace std;

const int MOD = 80112002;
const int N = 5010;
const int M = 500010;
int n, m;
int ind[N];
int outd[N];
vector<int> relation[N];
int dp[N];
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        relation[x].push_back(y);
        ind[y] ++;
        outd[x] ++;
    }
    queue<int> q;
    // 拓扑排序
    for(int i = 1; i <= n; i ++) {
        if (!ind[i]) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        for(int k : relation[t]) {
            ind[k] --;
            dp[k] += dp[t];
            dp[k] %= MOD;
            if (!ind[k]) {
                if (!outd[k]) {
                    ans += dp[k];
                    ans %= MOD;
                    continue; // 消费者出度为0.继续也无意义
                }
                q.push(k);
            }
        }
    }
    cout << ans;
    return 0;
}