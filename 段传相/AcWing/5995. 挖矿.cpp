#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, res = 0;
    cin >> n >> m;
    vector<int> z(2e6 + 10, 0), f(2e6 + 10, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            z[x]++;
        }
        else if (x < 0) {
            f[abs(x)]++;
        }
        else {
            res++;
        }
    }

    for (int i = 1; i <= 2e6 + 9; i++) {
        z[i] += z[i - 1];
        f[i] += f[i - 1];
    }
    int mx1 = 0, mx2 = 0;
    for (int i = 1, j = m; j >= 0; i++, j -= 2) {
        mx1 = max(mx1, z[i - 1] + f[j]);
        mx2 = max(mx2, z[j] + f[i - 1]);

        //cout<<z[i-1]+f[j]<<' '<<z[j]+f[i-1]<<endl;
    }
    cout << res + max(mx1, mx2);

}