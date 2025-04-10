#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = n; i > 0; i --) a[i] = a[i] - a[i - 1];
    
    for(int i = n; i > 0; i --) ans += abs(a[i] - a[i - 1]);
    cout << ans << "\n";
    return 0;
}
