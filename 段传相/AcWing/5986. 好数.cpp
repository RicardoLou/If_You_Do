#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, count = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x = i, flag = 1, f = 1;
        while (x > 0) {
            if (flag) {
                flag = 0;
                if (x % 10 % 2 != 1) {
                    f = 0;
                    break;
                }
            }
            else {
                flag = 1;
                if (x % 10 % 2 != 0) {
                    f = 0;
                    break;
                }
            }
            x /= 10;
        }
        if (f) {
            count++;
        }
    }
    cout << count;

}