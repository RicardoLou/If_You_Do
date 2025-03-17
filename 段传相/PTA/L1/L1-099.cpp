#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (b == 1) {
        cout << "-" << endl;
        if (a == 1) cout << "move" << endl;
        if (a == 0) cout << "stop" << endl;
        if (a == 2) cout << "stop" << endl;
    }
    if (b == 0) {
        if (a == 0) cout << "biii" << endl << "stop" << endl;
        if (a == 1) cout << "dudu" << endl << "move" << endl;
        if (a == 2) cout << "-" << endl << "stop" << endl;
    }
    return 0;
}