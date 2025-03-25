#include<bits/stdc++.h>
using namespace std;

int a[1001] = {}, flag = 1;
vector<int> b;

void find(int l, int r) {
    if (l > r) {
        return;
    }
    int ll = l + 1, rr = r;
    if (flag) {
        while (ll <= r && a[ll] < a[l]) {
            ll++;
        }
        while (rr > l && a[rr] >= a[l]) {
            rr--;
        }
    }
    else {
        while (ll <= r && a[ll] >= a[l]) {
            ll++;
        }
        while (rr > l && a[rr] < a[l]) {
            rr--;
        }
    }
    if (ll - rr != 1) {
        return;
    }
    find(l + 1, rr);
    find(ll, r);
    b.push_back(a[l]);
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    find(0, n - 1);
    if (b.size() != n) {
        b.clear();
        flag = 0;
        find(0, n - 1);
    }
    if (b.size() != n) {
        cout << "NO";
    }
    else {
        cout << "YES" << endl << b[0];
        for (int i = 1; i < n; i++) {
            cout << ' ' << b[i];
        }
    }
}