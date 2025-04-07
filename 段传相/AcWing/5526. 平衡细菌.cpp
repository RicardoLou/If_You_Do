#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //二阶差分
    int n;
    cin >> n;
    vector<ll> v1(n + 1, 0), v2(n + 1, 0), v3(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
    }
    for (int i = 1; i <= n; i++) {
        v2[i] = v1[i] - v1[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        v3[i] = v2[i] - v2[i - 1];
    }
    ll sum = 0;
    for (ll x : v3) {
        sum += abs(x);
    }
    cout << sum;

}