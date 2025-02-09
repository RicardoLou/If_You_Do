#include<bits/stdc++.h>
using namespace std;

int main() {

    char c;
    int n;
    cin >> c >> n;
    getchar();
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        reverse(s.begin(), s.end());
        replace(s.begin(), s.end(), '@', c);
        strs.insert(strs.begin(), s);
    }
    bool flag = 1;
    for (int i = 0; i < strs.size() / 2; i++) {
        if (strs[i] != strs[strs.size() - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        cout << "bu yong dao le" << endl;
    }
    for (auto s : strs) {
        cout << s << endl;
    }

}