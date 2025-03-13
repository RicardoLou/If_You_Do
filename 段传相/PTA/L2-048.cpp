#include<bits/stdc++.h>
using namespace std;

int n, m;
bool flag;
vector<vector<bool>> bj;//标记格子有没有被搜索过
vector<string> mp;

void dfs(int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || bj[y][x] == 1 || mp[y][x] == '0') {
        return;
    }
    if (mp[y][x] > '1') {
        flag = 1;
    }
    bj[y][x] = 1;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}


int main() {

    cin >> n >> m;
    bj = vector<vector<bool>>(n, vector<bool>(m, 0));
    //bj=move(bb);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp.push_back(s);
    }

    int dys = 0, bzs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bj[i][j] == 0 && mp[i][j] > '0') {
                dys++;
                flag = 0;
                dfs(j, i);
                if (flag) {
                    bzs++;
                }
            }
        }
    }
    cout << dys << ' ' << bzs;

}