#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        if (int(s[0] + s[1] + s[2]) == int(s[3] + s[4] + s[5])) {
            cout << "You are lucky!" << endl;
        }
        else {
            cout << "Wish you good luck." << endl;
        }
    }

}