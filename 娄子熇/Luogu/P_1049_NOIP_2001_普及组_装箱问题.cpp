#include<bits/stdc++.h>
using namespace std;

const int N = 31;
int v[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int V;
    cin >> V;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
    }
    vector<int> dp(V + 1, 0);
    for(int i = 1; i <= n; i ++) {
        for(int j = V; j >= v[i]; --j) {
                dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
    cout << V - dp[V];
    return 0;
}