#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int aa[n], pre[n + 1] = {};
    long long cnt = 0;
    unordered_map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        cin >> aa[i];
        pre[i + 1] = pre[i];
        if (++mp1[aa[i]] == 1) {
            pre[i + 1]++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (++mp2[aa[i]] == 2) {
            cnt += pre[i];
            if (mp1[aa[i]] > 2) {
                cnt--;
            }
        }

    }
    cout << cnt;

}