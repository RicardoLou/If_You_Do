#include<bits/stdc++.h>
using namespace std;

int main() {

    int a;
    cin >> a;
    int bb[a];
    for (int& s : bb) {
        cin >> s;
    }
    int k, i, y = 0, n = 0;
    cin >> k;
    while (k--) {
        for (int& x : bb) {
            cin >> i;
            if (x == i) {
                y++;
            }
            else if (i != 0 && i != x) {
                n++;
            }
        }
        if (y > 0 && n == 0) {
            cout << "Da Jiang!!!" << endl;
        }
        else if (y == 0 && n == 0) {
            cout << "Ai Ya" << endl;
        }
        else if (n > 0) {
            cout << "Ai Ya" << endl;
        }
        y = 0;
        n = 0;
    }

}