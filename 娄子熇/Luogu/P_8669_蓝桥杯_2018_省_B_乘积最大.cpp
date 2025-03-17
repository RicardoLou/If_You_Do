#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
long long MOD = 1000000009;
long long a[N];
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long res = 1;
    int flag = 1;
    int left = 0;
    int right = n - 1;
    // 如果是奇数就一定要先选择一个最大的，因为奇数情况，负数偶数个是最佳，即使最大值是偶数，也是乘上最大值最优，如果然后从两侧两两挑选，负负可能大于正正
    if (k % 2) {
        res *= a[right];
        k --;
        right --;
        if (res < 0) {
            flag = -1;
        }
    }
    while(k) {
        long long x = a[left] * a[left + 1];
        long long y = a[right] * a[right - 1];
        if (x * res > y * res) {
            left += 2;
            res = (x % MOD) * (res % MOD) % MOD;
        } else {
            right -= 2;
            res = (y % MOD) * (res % MOD) % MOD;
        }
        k -= 2;
    }
    printf("%lld", res);
    return 0;
}