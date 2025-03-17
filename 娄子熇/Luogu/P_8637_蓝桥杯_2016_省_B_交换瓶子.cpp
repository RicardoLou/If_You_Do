#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n;
int a[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;
    bool flag = true;
    // 考虑最坏的情况就是需要遍历n次
    while(n --) {
        for(int i = 1; i <= n; i ++) {
            if (a[i] != i) {
                ans ++;
                // 交换位置
                swap(a[i], a[a[i]]);
                flag = false;
                continue;
            }
        }
        if (flag) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}