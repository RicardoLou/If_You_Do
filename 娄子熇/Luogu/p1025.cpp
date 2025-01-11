#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
    for(int i = 1; i <= n; i ++) {
        f[i][0] = 1;
        f[i][1] = 1;
    }
    for(int i = 2; i <= k; i ++) {
        f[0][k] = 0;
        f[1][k] = 0;
    }
    for(int i = 2; i <= n; i ++) {
        for(int j = 2; j <= k; j ++) {
            if (i > j) {
                f[i][j] = f[i - 1][j - 1] + f[i - j][j];
            } else 
                f[i][j] = f[i - 1][j - 1];
        }
    }
    cout << f[n][k];
}