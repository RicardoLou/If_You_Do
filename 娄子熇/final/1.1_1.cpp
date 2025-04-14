#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x = 0;
    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        s += a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i += 2) {
        x += a[i];
    }
    cout << x - (s - x) << endl;
    return 0;
}