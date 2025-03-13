#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> rw(n, vector<bool>(m, false));
    // bool rw[n][m]={};
    // memset(rw,false,sizeof(rw));
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            rw[i][x - 1] = true;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b, count = 0;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (rw[i][a - 1] && rw[i][b - 1]) {
                count++;
            }
        }
        cout << count << endl;
    }

}