#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, s, count = 0, power = 1, fx = 1;
    cin >> n >> s;
    vector<int> v(n + 1), z(n + 1), f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> z[i];
    }
    int t = 0;
    while (true) {

        if (s <= 0 || s > n) {
            cout << count;
            break;
        }
        if (v[s] == 1) {
            if (f[s] == 0 && power >= z[s]) {
                f[s] = 1;
                v[s] = -1;
                count++;
                //cout<<s<<'-'<<power<<'-'<<z[s]<<endl;
            }
            s += fx * power;

        }
        else if (v[s] == 0) {
            fx *= -1;
            power += z[s];
            s += fx * power;
        }
        else {
            s += fx * power;
        }
        if (t++ == 1e6) {
            cout << count;
            break;
        }

    }

}