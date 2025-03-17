#include<bits/stdc++.h>
using namespace std;

int main() {

    int a[3][3], sum = 0;
    bool flag[9] = { 0,0,0,0,0,0,0,0,0 };
    int b[] = { 10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0) {
                flag[a[i][j] - 1] = 1;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        cout << a[x - 1][y - 1] << endl;
    }

    int f = 0;
    for (int i = 0; i < 9; i++) {
        if (flag[i] == 0) {
            f = i;
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0) {
                a[i][j] = f + 1;
            }
        }
    }

    int c;
    cin >> c;
    if (c < 4) {
        for (int i = 0; i < 3; i++) {
            sum += a[c - 1][i];
        }
    }
    else if (c > 3 && c < 7) {
        for (int i = 0; i < 3; i++) {
            sum += a[i][c - 4];
        }
    }
    else if (c == 7) {
        sum = a[0][0] + a[1][1] + a[2][2];
    }
    else if (c == 8) {
        sum = a[0][2] + a[1][1] + a[2][0];
    }
    cout << b[sum - 6];

}