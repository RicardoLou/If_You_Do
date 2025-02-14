#include<bits/stdc++.h>
using namespace std;

int main() {

    int a[24];
    for (int& x : a) {
        cin >> x;
    }
    int x;
    cin >> x;
    while (x >= 0 && x <= 23) {
        cout << a[x];
        if (a[x] > 50) {
            cout << " Yes" << endl;
        }
        else {
            cout << " No" << endl;
        }
        cin >> x;
    }
}