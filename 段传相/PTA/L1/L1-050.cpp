#include<bits/stdc++.h>
using namespace std;

int main() {

    int L, n;
    cin >> L >> n;
    string t;
    n = pow(26, L) - n;
    while (L--) {
        t.insert(0, string(1, char(n % 26 + 'a')));
        n /= 26;
    }
    cout << t;

}