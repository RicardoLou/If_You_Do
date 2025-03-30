#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, f, count = 0;
    string str;
    map<string, int> mm;
    cin >> n >> f >> str;
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (i == j) {
                continue;
            }
            string s;
            s += i;
            s += j;
            s += j;
            int index = str.find(s);
            while (index != string::npos) {
                mm[s]++;
                int a = f - 1;
                index = str.find(s, index + 3);

            }
            if (mm[s] == f - 1) {
                for (int k = 0; k < n - 2; k++) {
                    int flag = 0;
                    string s1 = str.substr(k, 3);
                    for (int l = -2; l <= 2; l++) {
                        if (k + l < n - 2 && k + l >= 0) {
                            string s2 = str.substr(k + l, 3);
                            if (s2 == s) {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        continue;
                    }
                    else if (s1[0] == s[0] && s1[1] == s[1] ||
                             s1[1] == s[1] && s1[2] == s[2] ||
                             s1[0] == s[0] && s1[2] == s[2]) {
                        mm[s]++;
                        break;
                    }
                }
            }
        }
    }
    for (auto x : mm) {
        if (x.second >= f) {
            count++;
        }
    }
    cout << count << endl;
    for (auto x : mm) {
        if (x.second >= f) {
            cout << x.first << endl;
        }
    }
}