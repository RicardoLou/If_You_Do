#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
int n, ans = 0;
int num[N] = {6,2,5,5,4,5,6,3,7,6};
int path[N];
void dfs(int u, int sum) {
    if (sum > n) 
        return;
    if (u >= 3) {
        if (sum == n && path[0] + path[1] == path[2]) {
            ans ++;
        }
        return;
    }
    for(int i = 0; i < 1000; i ++) {
        path[u] = i;
        dfs(u + 1, sum + num[path[u]]);
    }
}
int main() {
    cin >> n;
    if (n < 10) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 10; i < 1000; i ++) {
        num[i] = num[i % 10] + num[i / 10];
    }
    n -= 4;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}