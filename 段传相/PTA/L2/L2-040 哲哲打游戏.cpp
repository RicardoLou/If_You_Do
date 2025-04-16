#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> vv(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        vv[i] = vector<int>(a + 1);
        for (int j = 1; j <= a; j++) {
            cin >> vv[i][j];
        }
    }

    vector<int> cd(110);
    int idx = 1;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x;
        if (x == 0) {
            cin >> y;
            idx = vv[idx][y];
        }
        else if (x == 1) {
            cin >> y;
            cd[y] = idx;
            cout << idx << endl;
        }
        else if (x == 2) {
            cin >> y;
            idx = cd[y];
        }
    }
    cout << idx;
}