#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> l(m + 1), r(m + 1), b(n + 1, 0), s(n + 1, 0), pr0(n + 1, 0), pr1(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        b[l[i]]++;
        b[r[i] + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++) {
        pr0[i] = pr0[i - 1];
        pr1[i] = pr1[i - 1];
        if (s[i] == 0)pr0[i]++;
        if (s[i] == 1)pr1[i]++;
    }

    for (int i = 1; i <= m; i++) {
        cout << pr0[l[i] - 1] + pr0[n] - pr0[r[i]] + pr1[r[i]] - pr1[l[i] - 1] << endl;
    }

}