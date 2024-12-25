#include<bits/stdc++.h>
using namespace std;

int main() {
    int cnt[10] = {0};
    string n;
    cin >> n;
    for(int i = 0; i < n.length(); i ++) {
        char c = n[i];
        cnt[c - '0'] ++;
    }
    for(int i = 0; i < 10; i ++) {
        if (cnt[i] != 0) {
            cout << i << ":" << cnt[i] << endl;
        }
    }
    return 0;
}