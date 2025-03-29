#include <bits/stdc++.h>
using namespace std;

int main() {
    // 请在此处编写代码...
    int n;
    cin >> n;
    //unordered_map/unordered_set内部是乱序的，跟插入值时的顺序并不一样
    unordered_map<string, int> mp;
    vector<string> v;
    while (n--) {
        string s;
        cin >> s;
        mp[s]++;
        if (mp[s] == 1) {
            v.push_back(s);
        }
    }
    for (auto x : v) {
        cout << x << endl;
    }
    return 0;
}