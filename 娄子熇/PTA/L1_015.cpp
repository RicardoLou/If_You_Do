#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    char c;
    cin >> n >> c;
    for(int i = 1; i <= round(n / 2.0); i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}