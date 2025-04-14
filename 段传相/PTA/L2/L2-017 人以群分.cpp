#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), pre(n + 1);
    for (int& x : v) {
        cin >> x;
    }

    sort(v.begin(), v.begin() + n);
    //前缀和方便后面求范围内的和
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i - 1];
    }

    int l, r, diff;
    if (n % 2 == 0) {
        l = n / 2 - 1;
        r = l + 1;
        diff = pre[n] - pre[l + 1] - pre[l + 1];
    }
    else {
        l = n / 2;
        r = l + 1;
        diff = pre[n] - pre[l] - pre[l];
    }

    cout << "Outgoing #: " << r << endl;
    cout << "Introverted #: " << n - r << endl;
    cout << "Diff = " << diff;
}