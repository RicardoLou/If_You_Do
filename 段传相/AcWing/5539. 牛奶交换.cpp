#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> v(n * 2 - 1);
    ll res = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
        res += v[i];
        s += s[i];
    }

    int k = 0;
    while (k < n && s[k] == s[k + 1]) k++;

    if (k < n) {
        for (int i = k + 1; i <= n; i++) {
            ll sum = 0;
            int j = i;
            while (j <= k + n && s[j] == s[i]) {
                sum += v[j];
                j++;
            }
            if (s[i] == 'R') {
                sum -= v[j - 1];
            }
            else {
                sum -= v[i];
            }
            res -= min(sum, ll(m));
            i = j - 1;
        }
    }
    cout << res;

}