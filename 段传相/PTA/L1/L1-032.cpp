#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, nn;
    char c;
    cin >> n >> c;
    nn = n;
    string str;
    getchar();
    getline(cin, str);
    if (str.length() <= n) {
        string str_re = string(str.rbegin(), str.rend());
        while (nn - str.length()) {
            str_re += c;
            nn--;
        }
        cout << string(str_re.rbegin(), str_re.rend());
    }
    else {
        cout << str.substr(str.length() - n, str.length());
    }
    return 0;
}