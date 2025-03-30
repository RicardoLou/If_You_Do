#include<bits/stdc++.h>
using namespace std;

int main() {

    //加这个可以快很多
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {

        int N;
        long long sum = -1;
        cin >> N;
        vector<long long> pre(N + 1, 0);
        for (int n = 1; n <= N; n++) {
            int x;
            cin >> x;
            pre[n] = pre[n - 1] + x;
        }
        for (int i = 0; i <= N / 2 - 1; i++) {
            sum = max(sum, (pre[i] + pre[N] - pre[N / 2 - 1 + i + 2]));
        }
        cout << pre[N] - sum << " " << sum << endl;

    }

}