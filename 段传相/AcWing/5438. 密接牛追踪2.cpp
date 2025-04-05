#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, flag1 = 0, flag2 = 0;
    string s;
    cin >> n >> s;
    s += '0';//加个0标志结束

    if (flag1 == 0 && s[0] == '1') {
        flag1 = 1;//开头有牛
    }

    vector<int> v;
    //cout<<s<<endl;
    for (int i = 0, j = 0; i <= n; i++) {
        if (s[i] == '0') {
            continue;
        }
        j++;
        if (i + 1 <= n && s[i + 1] == '0') {

            if (i == s.length() - 2) {
                flag2 = 1;//结尾有牛
            }
            v.push_back(j - 1);
            j = 0;
        }
    }

    // cout<<flag1<<flag2<<endl;
    // for(int x:v){
    //     cout<<x<<endl;
    // }

    if (v.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    int r = 1e9;
    for (int i = 0; i < v.size(); i++) {
        if ((flag1 == 1 && i == 0) || (flag2 == 1 && i == v.size() - 1)) {
            r = min(v[i] + 1, r);
        }
        else {
            r = min((v[i] + 2) / 2, r);
        }
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += v[i] / (2 * r - 1) + 1;
    }
    cout << ans << endl;
    return 0;

}