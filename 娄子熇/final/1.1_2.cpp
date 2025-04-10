#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        string s;
        cin >> s;
        int mismatch1 = 0, mismatch2 = 0;
        for (int i = 0; i < 2 * n; i++) {
            char expected1 = (i % 2 == 0) ? 'A' : 'B';  // ABAB...
            char expected2 = (i % 2 == 0) ? 'B' : 'A';  // BABA...
            if (s[i] != expected1) mismatch1++;
            if (s[i] != expected2) mismatch2++;
        }
        cout << min(mismatch1, mismatch2) / 2 << endl;
    }
    return 0;
}