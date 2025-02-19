#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n, n));
    vector<vector<int>> b(n, vector<int>(n, n));
    vector<vector<int>> c(n, vector<int>(n, n));
    int ans = 0;
    while(q --) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] --;b[x][z] --; c[y][z] --;
        ans += (a[x][y] == 0) + (b[x][z] == 0) + (c[y][z] == 0);
        cout << ans << endl;
    }
    return 0;
}