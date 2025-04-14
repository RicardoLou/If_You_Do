#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // 请在此输入您的代码

    ll m = 1000000;
    set<ll> st;
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= m; j++) {

            ll x = i * j, a = i, b = j;
            ll f = x;
            if (x > m) {
                break;
            }
            vector<int> v(10, 0);
            while (x > 0) {
                v[x % 10]++;
                x /= 10;
            }
            while (a > 0) {
                v[a % 10]--;
                a /= 10;
            }
            while (b > 0) {
                v[b % 10]--;
                b /= 10;
            }
            bool flag = 1;
            for (auto q : v) {
                if (q != 0) {
                    flag = 0;
                }
            }
            if (flag) {
                st.insert(f);
                //cout<<f<<' '<<i<<' '<<j<<endl;
            }

        }
    }
    cout << st.size();
    return 0;
}