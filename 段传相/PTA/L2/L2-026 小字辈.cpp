#include<bits/stdc++.h>
using namespace std;

struct peo {
    int id;
    int level;
};

int main() {

    //BFS
    int n, temp, maxlevel = 0;
    cin >> n;
    queue<peo> q;
    vector<peo> ans;
    vector<vector<int>> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (temp == -1) {
            temp = 0;
        }
        v[temp].push_back(i);
    }
    q.push({ 0,0 });
    while (!q.empty()) {
        peo p = q.front();
        int id = p.id, level = p.level;
        if (p.level > maxlevel) {
            maxlevel = p.level;
        }
        ans.push_back(p);
        q.pop();
        for (int i = 0; i < v[id].size(); i++) {
            q.push({ v[id][i],level + 1 });
        }
    }
    cout << maxlevel << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i].level == maxlevel) {
            cout << ans[i].id;
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
    }

}

//dfs有两个点超时
void DFS() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int p[n + 1], f[n + 1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    unordered_map<int, vector<int>> mp;
    int count, max = 0;
    auto&& dfs = [&count, &p, &f, &mp](auto&& dfs, int id)->void {
        if (p[id] == -1) {
            return;
        }
        count++;
        if (f[id] == 0) {
            f[id] = 1;
            f[p[id]] = 1;
        }
        dfs(dfs, p[id]);
        };
    for (int i = 1; i <= n; i++) {
        count = 0;
        if (f[i] == 0) {
            dfs(dfs, i);
            if (count + 1 >= max) {
                max = count + 1;
                mp[max].push_back(i);
            }
        }
    }
    //auto it=*mp.rbegin();
    sort(mp[max].begin(), mp[max].end());
    cout << max << endl;
    for (auto x = mp[max].begin(); x != mp[max].end(); x++) {
        if (x == mp[max].begin()) {
            cout << *x;
        }
        else {
            cout << " " << *x;
        }
    }

}