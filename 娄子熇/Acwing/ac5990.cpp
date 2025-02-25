#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1010, M = N * N / 2 + 10;
int n;
LL s[N], range[M];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        int t;
        scanf("%d", &t);
        s[i] = s[i - 1] + t;
    }
    if (n == 2) {
        cout << s[2] - s[1] - s[1];
        return 0;
    }
    int index = 0;
    // 记录每一种连续的选法
    for(int i = 1; i <= n; i ++) {
        for(int j = i; j <= n; j ++) {
            
            range[index ++] = s[j] - s[i - 1];
        }
    }
    sort(range, range + index);

    LL ans = 1e9; // a[i]最大值是1e9，所以差值一定不会超过1e9
    for(int i = 1; i < index; i ++) 
        ans = min(ans, range[i] - range[i - 1]);
    cout << ans;
    return 0;
}