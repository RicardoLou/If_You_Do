#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n, r;
int path[N];
void dfs(int u) {
    // 这里u是从1开始的
    if (u > r) {
        for(int i = 1; i <= r; i ++) {
            printf("%3d", path[i]); 
        }
        printf("\n");
        return;
    }
    for(int i = path[u - 1] + 1; i <= n; i ++) {
            path[u] = i;
            dfs(u + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    dfs(1);
}