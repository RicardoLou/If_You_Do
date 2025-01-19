#include<bits/stdc++.h>
using namespace std;

int main() {

    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.length(); i++) {
        for (int j = 0; j < 10000; j++) {
            int k = a.find(b[i]);
            if (k >= 0) {
                a.erase(k, 1);
            }
            else {
                break;
            }
        }
    }
    cout << a << endl;

}