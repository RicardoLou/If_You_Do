#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, i, s = 1;
    char c;
    cin >> n >> c;
    for (i = 3; s + (i * 2) < n; i += 2) {
        s += i * 2;
    }
    for (int j = i - 2; j > 0; j -= 2) {
        for (int a = (i - j) / 2 - 1; a > 0; a--) {
            cout << " ";
        }
        for (int k = j; k > 0; k--) {
            cout << c;
        }
        cout << endl;
    }
    for (int j = 3; j < i; j += 2) {
        for (int a = (i - j) / 2 - 1; a > 0; a--) {
            cout << " ";
        }
        for (int k = j; k > 0; k--) {
            cout << c;
        }
        cout << endl;
    }
    cout << n - s;

}