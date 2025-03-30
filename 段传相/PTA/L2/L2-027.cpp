#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, g, k, sum = 0;
    cin >> n >> g >> k;
    map<int, set<string>> mp;
    for (int i = 0; i < n; i++) {
        string name;
        int cj;
        cin >> name >> cj;
        if (cj >= 60) {
            sum += 20;
            if (cj >= g) {
                sum += 30;
            }
        }
        mp[cj].insert(name);
    }
    cout << sum << endl;

    int i = 1, j = 1;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        int cj = it->first;
        for (auto x = it->second.begin(); x != it->second.end();) {
            cout << i << ' ' << *x << ' ' << cj << endl;
            j++;
            if (++x == it->second.end() && j > k) {
                return 0;
            }
        }
        i = j;
    }
}