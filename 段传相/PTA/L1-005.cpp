#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<string>> xxs;
    for (int i = 0; i < n; i++) {
        vector<string> ss;
        string s;
        for (int j = 0; j < 3; j++) {
            cin >> s;
            ss.push_back(s);
        }
        xxs.push_back(ss);
    }
    int m;
    cin >> m;
    int ms[m];
    for (int i = 0; i < m; i++) {
        cin >> ms[i];
    }
    for (auto a : ms) {
        for (auto ss : xxs) {
            if (stoi(ss[1]) == a) {
                cout << ss[0] << " " << ss[2] << endl;
            }
        }
    }

}