#include<bits/stdc++.h>
using namespace std;

struct NODE {
    int id, fid, mid;
    string sex;
}aa[100000];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        aa[id].id = id;
        cin >> aa[id].sex >> aa[id].fid >> aa[id].mid;
        if (aa[id].fid != -1) {
            aa[aa[id].fid].sex = "M";
        }
        if (aa[id].mid != -1) {
            aa[aa[id].mid].sex = "F";
        }
    }

    map<int, int> zz;
    auto&& dfs = [&](auto&& dfs, int id, int cnt)->void {
        if (id == 0 || id == -1 || cnt >= 5) {
            return;
        }
        zz[id]++;
        dfs(dfs, aa[id].fid, cnt + 1);
        dfs(dfs, aa[id].mid, cnt + 1);
        return;
        };

    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (aa[a].sex == aa[b].sex) {
            cout << "Never Mind" << endl;
            continue;
        }
        dfs(dfs, a, 0);
        dfs(dfs, b, 0);

        int flag = 0;
        for (auto x : zz) {
            //cout<<x.first<<' '<<x.second<<endl;
            if (x.second >= 2) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }

        zz.clear();
    }

}