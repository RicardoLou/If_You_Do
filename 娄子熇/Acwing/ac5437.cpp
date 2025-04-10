#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;
vector<long long> a(N);
vector<long long> b(N);
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++) {
        cin >> b[i];
    }
    // 枚举每根糖
    for(int i = 1; i <= m; i ++) {
        long long h = 0; // 每根糖果当前高度
        for(int j = 1; j <= n; j ++) {
            if (a[j] > h) {
                int t = min(a[j], b[i]) - h; // 吃掉的长度
                h += t;
                a[j] += t;
                // 剪枝，没这个优化居然过不去。。
                if (h >= b[i]) break;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        cout << a[i] << endl;
    }
    return 0;
}