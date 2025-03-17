#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
long double a[N];
int main() {
    int n;
    long double s;
    cin >> n >> s;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long double avg = s / (n * 1.0);
    long double mn = 0;
    long double ans = 0;
    for(int i = 1; i <= n; i ++) {
        mn = min(a[i], s / (n - i + 1));
        s -= mn;
        // 标准差
        ans += (mn - avg) * (mn - avg);
    }
    printf("%.4Lf", sqrt(ans / n));
    return 0;
}