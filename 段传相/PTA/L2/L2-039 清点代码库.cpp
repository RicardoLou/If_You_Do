#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    map<vector<int>, int> mp;
    map<int, set<vector<int>>> ms;

    while (n--) {
        vector<int> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }
        mp[v]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        ms[it->second].insert(it->first);
    }

    cout << mp.size() << endl;
    for (auto it = ms.rbegin(); it != ms.rend(); it++) {
        for (auto i = it->second.begin(); i != it->second.end(); i++) {
            cout << it->first;
            for (auto x : *i) {
                cout << ' ' << x;
            }
            cout << endl;
        }
    }

}