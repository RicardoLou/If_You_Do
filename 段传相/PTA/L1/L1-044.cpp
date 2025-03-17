#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, count = 0;
    cin >> n;
    string s[3] = { "ChuiZi","JianDao","Bu" };
    while (1) {
        string c;
        cin >> c;

        if (c == "End") {
            break;
        }
        else if (count++ == n) {
            count = 0;
            cout << c << endl;
        }
        else if (c == s[0]) {
            cout << s[2] << endl;
        }
        else if (c == s[1]) {
            cout << s[0] << endl;
        }
        else if (c == s[2]) {
            cout << s[1] << endl;
        }
    }

}