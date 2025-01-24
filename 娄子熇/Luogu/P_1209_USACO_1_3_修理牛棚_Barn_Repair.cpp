#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int a[N];
int b[N];
int m, s, c;

bool cmp(const int& a, const int& b) {
    return a > b;
}
int main() {
    cin >> m >> s >> c;
    // 板子比牛多，每个牛一块板子
    if (m >= c) {
        cout << c;
        return 0;
    }
    for(int i = 0; i < c; i ++) {
        cin >> a[i];
    }
    sort(a, a + c);
    // 差值，也就是断开的值
    for(int i = 1; i < c; i ++) {
        b[i] = a[i] - a[i - 1];
    }
    sort(b, b + c + 1, cmp);
    int ans = a[c - 1] - a[0] + 1; // 开始只有一个木板
    // 单个木板的长度
    for(int i = 0; i < m - 1; i ++) {
        ans -= b[i] - 1;
    }
    cout << ans;
    return 0;
}