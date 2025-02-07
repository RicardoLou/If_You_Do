#include<bits/stdc++.h>
using namespace std;

int main() {

    int count = 0;
    string s, a, b;

    while (1) {
        cin >> s;
        if (s[0] == '.') {
            break;
        }
        count++;
        if (count == 2) {
            a = s;
        }
        if (count == 14) {
            b = s;
        }
    }

    if (a != "" && b != "") {
        cout << a << " and " << b << " are inviting you to dinner...";
    }
    if (a != "" && b == "") {
        cout << a << " is the only one for you...";
    }
    if (a == "" && b == "") {
        cout << "Momo... No one is for you ...";
    }

}