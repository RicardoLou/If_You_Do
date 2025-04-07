#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//先利用等差数列求和公式看计算结果的规律
//发现2，4，8，16，32...不符合题意
const ll N = 1e16;
unordered_map<ll, int> mp;
void init() {
    ll t = 1;
    while (t <= N) {
        //cout<<t<<' ';
        mp[t] = 1;
        t <<= 1;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, count = 0;
    cin >> n;
    init();
    while (n--) {
        ll x;
        cin >> x;
        if (mp[x] == 1) {
            count++;
        }

    }
    cout << count;

}