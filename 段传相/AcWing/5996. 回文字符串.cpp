#include<bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    while (N--) {

        string s;
        cin >> s;

        long long l, r, n = s.length(), k = 0;
        for (l = 0; l < n; l++) {
            if (s[l] != 'l' && s[l] != 'q' && s[l] != 'b') {
                break;
            }
        }
        for (r = n - 1; r >= 0; r--) {
            if (s[r] != 'l' && s[r] != 'q' && s[r] != 'b') {
                break;
            }
        }

        int flag = 1, i = l, j = r;
        if (r <= 0) {
            flag = 1;
        }
        else {
            while (i < j) {
                if (s[i] != s[j]) {
                    flag = 0;
                    break;
                }
                i++;
                j--;
            }
            if (flag == 1) {
                for (; l >= 0 && r < n && s[l] == s[r]; l--, r++); //看一下A的序列是否和C前缀一样
                if (l == -1)  flag = 1;
                else flag = 0;;
            }
        }

        if (flag) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

}