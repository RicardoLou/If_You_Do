#include<bits/stdc++.h>
using namespace std;

int main() {

    //邻接表
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vv(n + 1);
    vector<int> v1(n + 1, 0), v2;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v1[a]++;
        v1[b]++;
        vv[a].push_back(b);
        vv[b].push_back(a);
    }

    int k;
    cin >> k;
    while (k--) {
        v2 = v1;
        int p;
        cin >> p;
        for (int i = 0; i < p; i++) {
            int e;
            cin >> e;
            v2[e] = 0;
            for (int j = 0; j < vv[e].size(); j++) {
                v2[vv[e][j]]--;
            }
        }

        int flag = 0;
        for (int x : v2) {
            if (x > 0) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }

}

//邻接矩阵，最后两点过不了
void test() {

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> vv(n + 1, vector<bool>(n + 1, 0));
    int sum = 0, sum2 = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vv[x][y] = vv[y][x] = 1;
        //sum+=2;
    }
    int k;
    cin >> k;
    while (k--) {
        vector<vector<bool>> vv1 = vv;
        sum2 = 0;
        int a;
        cin >> a;
        for (int i = 0; i < a; i++) {
            int b;
            cin >> b;
            for (int j = 1; j <= n; j++) {
                vv1[b][j] = vv1[j][b] = 0;
                //sum2-=2;
            }
        }

        int flag = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sum2 += vv1[i][j] + vv1[j][i];
                if (sum2) {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            cout << "YES" << endl;
        }
    }

}