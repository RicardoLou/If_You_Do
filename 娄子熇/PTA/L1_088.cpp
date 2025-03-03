#include <bits/stdc++.h>
using namespace std;

const int N = 300;
vector<int> inf(N);

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a >= 175) {
            // 一定可以被选上
            if (b >= s) {
                ans ++;
            } else {
                inf[a] ++;
            }
        }
    }
    for(int i = 175; i <= 290; i ++) {
        ans += min(inf[i], k);
    }

    cout << ans;
    return 0;
}