#include<bits/stdc++.h>
using namespace std;

int main() {

    int a;
    cin >> a;
    string s;
    getchar();
    getline(cin, s);
    int b = (s.length() % a == 0) ? (s.length() / a) : (s.length() / a + 1);
    char c[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            c[i][j] = ' ';
        }
    }

    int k = 0;
    for (int i = b - 1; i >= 0; i--) {
        for (int j = 0; j < a; j++) {
            if (k == s.length()) {
                break;
            }
            c[j][i] = s[k];
            k++;
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << c[i][j];
        }
        cout << endl;
    }

}