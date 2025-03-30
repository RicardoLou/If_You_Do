#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, jz[10][10] = {}, sz[10] = {}, sz1[10] = {}, flag = 1, flag1 = 1;
    cin >> n;

    while (n--) {

        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                cin >> jz[i][j];
            }
        }

        for (int i = 1; i < 10; i++) {
            flag = 1;
            memset(sz, 0, sizeof(sz));
            memset(sz1, 0, sizeof(sz1));
            for (int j = 1; j < 10; j++) {
                sz[jz[i][j]]++;
                sz1[jz[j][i]]++;
            }
            for (int j = 1; j < 10; j++) {
                if (sz[j] > 1 || sz[j] == 0 || sz1[j] > 1 || sz1[j] == 0) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }

        flag1 = 1;
        for (int x = 1; x <= 7; x += 3) { // x, y 表示每个3x3宫格的左上角坐标 
            for (int y = 1; y <= 7; y += 3) {
                memset(sz, 0, sizeof(sz));
                for (int i = x; i < x + 3; i++) {
                    for (int j = y; j < y + 3; j++) {
                        sz[jz[i][j]]++;
                    }
                }
                for (int j = 1; j < 10; j++) {
                    if (sz[j] > 1 || sz[j] == 0) {
                        flag1 = 0;
                        break;
                    }
                }
                if (!flag1) break;
            }
        }

        if (flag && flag1) {
            //cout<<flag<<" "<<flag1<<endl;
            cout << 1 << endl;
        }
        else {
            //cout<<flag<<" "<<flag1<<endl;
            cout << 0 << endl;
        }
    }

}