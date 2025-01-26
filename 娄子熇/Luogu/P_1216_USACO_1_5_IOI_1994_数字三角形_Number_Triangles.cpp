#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int g[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j <= i; j ++) {
            cin >> g[i][j];
        }
    }

    for(int i = n - 2; i >= 0; i --) {
        for(int j = 0; j <= i; j ++) {
            g[i][j] += max(g[i + 1][j], g[i + 1][j + 1]);
        }
    }
    cout << g[0][0];
    return 0;
}