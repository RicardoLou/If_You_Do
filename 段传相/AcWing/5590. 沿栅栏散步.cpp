#include<bits/stdc++.h>
using namespace std;
//未完成
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;

    map<pair<int, int>, int> zb;
    int lx, ly, b_x, b_y, e_x, e_y;
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        zb[{x, y}] = 0;
        if (i > 0) {
            zb[{x, y}] = zb[{lx, ly}] + abs(x - lx + y - ly);
            while (lx != x && ly != y) {
                if (lx < x) {
                    zb[{lx + 1, y}] = zb[{lx, ly}] + 1;
                    zb[{x, y}]++;
                    lx++;
                }
                if (ly < y) {
                    zb[{lx, y + 1}] = zb[{lx, ly}] + 1;
                    ly++;
                    zb[{x, y}]++;
                }
                if (lx > x) {
                    zb[{lx - 1, y}] = zb[{lx, ly}] - 1;
                    zb[{x, y}]++;
                    lx--;
                }
                if (ly > y) {
                    zb[{lx, y - 1}] = zb[{lx, ly}] - 1;
                    zb[{x, y}]++;
                    ly--;
                }
            }

        }
        else {
            b_x = x;
            b_y = y;
        }
        lx = x;
        ly = y;
    }
    for (auto x : zb) {
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    int zc = zb.rbegin()->second + abs(zb.begin()->first.first - zb.rbegin()->first.first + zb.begin()->first.second - zb.rbegin()->first.second);
    cout << zc << endl;

    while (n--) {
        int bx, by, ex, ey;
        cin >> bx >> by >> ex >> ey;
        int t = abs(zb[{ex, ey}] - zb[{bx, by}]);
        int z_t = abs(zc - t);
        cout << min(t, z_t) << endl;
    }

}