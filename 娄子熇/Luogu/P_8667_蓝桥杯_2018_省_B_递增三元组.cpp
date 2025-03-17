#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100010;
int A[N];
int B[N];
int C[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> A[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> B[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> C[i];
    }
    sort(A, A + n);
    sort(C, C + n);
    int ans = 0;
    for(int j = 0; j < n; j ++) {
        int cnta = lower_bound(A, A + n, B[j]) - A; // 小于B[j]的有多少个
        int cntc = upper_bound(C, C + n, B[j]) - C; // 找到大于他的第一个数
        cntc = n - cntc; // 大于B[j]的有多少个
        ans += cnta * cntc; // 乘法原理
    }
    cout << ans;
    return 0;
}