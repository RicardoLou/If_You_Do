#include<bits/stdc++.h>
using namespace std;

int main() {

    string ss;
    getline(cin, ss);
    int len = ss.length(), i, j, k, t;
    for (i = len; i >= 2; i--) {
        for (j = 0; j + i < len; j++) {
            for (k = j, t = j + i; k <= t; k++, t--) {
                if (ss[k] != ss[t]) {
                    break;
                }
            }
            if (k > t) {
                break;
            }
        }
        if (j + i < len) {
            break;
        }
    }
    if (i >= 2) {
        cout << i + 1;
    }
    else {
        cout << 1;
    }
}