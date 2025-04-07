#include<bits/stdc++.h>
using namespace std;

int main() {
    //o神的思路
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << (s.back() == '0' ? 'E' : 'B') << endl;
    }

}