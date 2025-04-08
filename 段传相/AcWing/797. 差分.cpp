#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0), v1(n + 1, 0), v2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
        v[i] = v1[i] - v1[i - 1];
        //cout<<v[i]<<' ';
    }
    //cout<<endl;

    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        v[l] += c;
        v[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        v2[i] = v2[i - 1] + v[i];
        if (i == 1) {
            cout << v2[i];
        }
        else {
            cout << ' ' << v2[i];
        }
    }

}