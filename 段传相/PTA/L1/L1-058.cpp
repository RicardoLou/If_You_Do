#include <bits/stdc++.h>
using namespace std;

int main() {

    string s, ans = "";
    int count = 0;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '6') {
            count++;
        }
        if (s[i] != '6' || i == s.size() - 1) {
            if (count > 9) {
                ans += "27";
            }
            else if (count > 3) {
                ans += "9";
            }
            else if (count > 0) {
                for (int i = 0; i < count; i++) {
                    ans += '6';
                }
            }
            if (s[i] != '6') {
                ans += s[i];
            }
            count = 0;
        }
    }
    cout << ans << endl;

}
