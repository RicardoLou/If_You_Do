#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    double z, r;
    cin >> n >> z >> r;
    vector<vector<int>> vv(n);
    vector<double> glz(n), fd(n, 1);
    glz[0] = z;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            for (int j = 0; j < x; j++) {
                int y;
                cin >> y;
                vv[i].push_back(y);
            }
        }
        else {
            int y;
            cin >> y;
            fd[i] = y;
        }
    }

    double sum = 0;
    auto&& dfs = [&](auto&& dfs, int jd, int fi)->void {
        if (vv[jd].size() == 0) {
            glz[jd] = (glz[fi] - glz[fi] * r / 100) * fd[jd];
            sum += glz[jd];
            return;
        }
        if (jd != 0) {
            glz[jd] = glz[fi] - glz[fi] * r / 100;
        }
        for (auto x : vv[jd]) {
            dfs(dfs, x, jd);
        }
        return;
        };

    dfs(dfs, 0, 0);
    if (vv[0].size() == 0) {
        cout << int(z * fd[0]);
    }
    else {
        cout << int(sum);
    }

}