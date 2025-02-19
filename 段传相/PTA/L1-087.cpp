#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m, q, count = 0;
    cin >> n >> m >> q;
    int gz[n][m] = {};

    while (q--) {
        int t, c;
        cin >> t >> c;
        if (t == 0) {
            for (int i = 0; i < m; i++) {
                gz[c - 1][i] = 1;
            }
        }
        else if (t == 1) {
            for (int i = 0; i < n; i++) {
                gz[i][c - 1] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout<<gz[i][j]<<' ';
            if (gz[i][j] == 0) {
                count++;
            }
        }
        //cout<<endl;
    }
    cout << count;

}