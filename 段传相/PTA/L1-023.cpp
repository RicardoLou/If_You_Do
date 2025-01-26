#include<bits/stdc++.h>
using namespace std;

int main() {

    string str;
    int s[4] = { 0 };
    cin >> str;
    for (char c : str) {
        if (c == 'G' || c == 'g') {
            s[0]++;
        }
        else if (c == 'P' || c == 'p') {
            s[1]++;
        }
        else if (c == 'L' || c == 'l') {
            s[2]++;
        }
        else if (c == 'T' || c == 't') {
            s[3]++;
        }
    }
    for (int i = 0; i < 10000; i++) {
        if (s[0] > 0) {
            cout << 'G';
            s[0]--;
        }
        if (s[1] > 0) {
            cout << 'P';
            s[1]--;
        }
        if (s[2] > 0) {
            cout << 'L';
            s[2]--;
        }
        if (s[3] > 0) {
            cout << 'T';
            s[3]--;
        }
    }

}