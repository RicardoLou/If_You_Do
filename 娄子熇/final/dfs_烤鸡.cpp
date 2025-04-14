#include<bits/stdc++.h>
using namespace std;

const int N = 60000;
int path[15];
int n, res = 0;
int ans[N][15];
void dfs(int u, int sum) {
    if (u >= 10) {
        if (sum == n) {    
            res ++;
            for(int i = 0; i < 10; i ++) {
                ans[res][i] = path[i];
            }
        }
        return;
    }
    for(int i = 1; i <= 3; i ++) {
        path[u] = i;
        dfs(u + 1, sum + i);
    }
}
int main() {
    cin >> n;
    dfs(0, 0);
    cout << res << endl;
    for(int i = 1; i <= res; i ++) {
        for(int j = 0; j < 10; j ++) 
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}