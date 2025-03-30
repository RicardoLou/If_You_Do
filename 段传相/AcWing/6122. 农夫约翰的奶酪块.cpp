#include<bits/stdc++.h>
using namespace std;
//逻辑应该没问题,在n=1000后会超时
int main() {

    int n, q, count = 0;
    cin >> n >> q;
    vector<vector<vector<bool>>> mp(n, vector(n, vector(n, false)));
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        mp[x][y][z] = 1;
        int co[6] = { 0,0,0,0,0,0 };
        //从当前点向上下左右前后扩展，记录一条有多少空的格子
        for (int j = 1; j < n; j++) {
            if (x - j >= 0) {
                if (mp[x - j][y][z] == 1) {
                    co[0]++;
                }
            }
            if (x + j < n) {
                if (mp[x + j][y][z] == 1) {
                    co[1]++;
                }
            }
            if (y - j >= 0) {
                if (mp[x][y - j][z] == 1) {
                    co[2]++;
                }
            }
            if (y + j < n) {
                if (mp[x][y + j][z] == 1) {
                    co[3]++;
                }
            }
            if (z - j >= 0) {
                if (mp[x][y][z - j] == 1) {
                    co[4]++;
                }
            }
            if (z + j < n) {
                if (mp[x][y][z + j] == 1) {
                    co[5]++;
                }
            }
        }
        for (int a : co) {
            if (a == n - 1) {
                count++;
            }
        }
        if (n > 2) {
            if (co[0] != n - 1 && co[1] != n - 1 && co[0] + co[1] == n - 1) {
                count++;
            }
            if (co[2] != n - 1 && co[3] != n - 1 && co[2] + co[3] == n - 1) {
                count++;
            }
            if (co[4] != n - 1 && co[5] != n - 1 && co[4] + co[5] == n - 1) {
                count++;
            }
        }
        cout << count << endl;
    }

}