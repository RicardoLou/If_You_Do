#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
vector<bool> st(N + 1, false);
int n;
bool flag = false;

// 筛质数 把不是质数的打上true
void getPrimes() {
    st[0] = st[1] = true;
    for(int i = 2; i * i <= N; i ++) {
        if (st[i]) continue;
        for(int j = i * i; j <= N; j += i) {
            st[j] = true;
        }
    }
}

void dfs(string &s, int cur, int v) {
    if (cur == s.size()) {
        if (v < N && !st[v]) {
            cout << v << endl;
            flag = true;
        }
        return;
    }
    if (s[cur] != '*') {
        dfs(s, cur + 1, 10 * v + (s[cur] - '0'));
    } else {
        for(int i = 0; i <= 9 && !flag; i ++) {
            dfs(s, cur + 1, v * 10 + i);
        }
    }
}

int main() {
    cin >> n;
    getPrimes();
    while(n --) {
        string x;
        cin >> x;
        flag = false;
        dfs(x, 0, 0);
        if (!flag) cout << -1 << endl;
    }
    return 0;
}