#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, a, b;
    cin >> n;
    vector<string> names;
    string name;
    while (n > 0) {
        cin >> name >> a >> b;
        if ((a >= 15 && a <= 20) && (b >= 50 && b <= 70)) {
            n--;

        }
        else {
            names.push_back(name);
            n--;
        }
    }
    for (string na : names) {
        cout << na << endl;
    }
    return 0;
}