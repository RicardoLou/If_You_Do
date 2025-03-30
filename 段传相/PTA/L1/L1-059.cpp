#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    while (n--) {
        bool flag1 = 0, flag2 = 0;
        getchar();
        vector<string> strs;
        string s;
        while (1) {
            cin >> s;
            strs.push_back(s);
            if (s[s.size() - 1] == ',') {
                if (s.size() > 3 && s.find("ong") == s.size() - 4) {
                    flag1 = 1;
                }
            }
            else if (s[s.size() - 1] == '.') {
                if (s.size() > 3 && s.find("ong") == s.size() - 4) {
                    flag2 = 1;
                }
                if (flag1 && flag2) {
                    strs[strs.size() - 1] = "zhong.";
                    strs[strs.size() - 2] = "ben";
                    strs[strs.size() - 3] = "qiao";
                }
                else {
                    cout << "Skipped" << endl;
                    break;
                }
                for (int i = 0; i < strs.size() - 1; i++) {
                    cout << strs[i] << ' ';
                }
                cout << strs[strs.size() - 1] << endl;
                break;
            }
        }
        strs.clear();
    }

}