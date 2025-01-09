#include<bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<string> higher;
    cin >> n >> m;
    string s;
    getline(cin, s); // 把数字后面换行读掉
    for(int i = 0; i < n; i ++) {
        getline(cin, s);
        higher.insert(s);
    }
    for(int i = 0; i < m; i ++) {
        getline(cin, s);
        if (higher.find(s) != higher.end()) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}