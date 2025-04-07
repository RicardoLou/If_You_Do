#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> c(n), t(n);
    for (int& x : c) {
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        c[i] -= t[i];
    }

    sort(c.begin(), c.end());
    // for(int x:c){
    //     cout<<x<<' ';
    // }
    // cout<<endl;
    while (q--) {

        int v, s, count = 0;
        cin >> v >> s;
        int p = distance(upper_bound(c.begin(), c.end(), s), c.end());
        if (v <= p) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }

}