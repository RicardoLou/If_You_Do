#include <bits/stdc++.h>
using namespace std;

int main() {
    // 请在此处编写代码...
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    while (m--) {

        int l, r;
        cin >> l >> r;
        string xs = s.substr(l - 1, r - l + 1);
        s.erase(l - 1, r - l + 1);
        s += xs;

    }
    cout << s;
    return 0;
}