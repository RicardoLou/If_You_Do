#include <bits/stdc++.h>
using namespace std;

int main() {
    // 请在此处编写代码...
    int n;
    double sum = 0;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int x : v) {
        sum += x;
    }
    sum /= 2;
    for (int i = 0; i < n; i++) {
        if (v[i] * 1.0 == sum) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}