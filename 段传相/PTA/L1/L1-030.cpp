#include<bits/stdc++.h>
using namespace std;

int main() {

    int m;
    cin >> m;
    vector<string> name;
    vector<bool> sex;
    int flag[m] = { 0 };
    bool x;
    string s;
    for (int i = 0; i < m; i++) {
        cin >> x >> s;
        sex.push_back(x);
        name.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (flag[i] == 0 && flag[j] == 0 && sex[i] != sex[j]) {
                cout << name[i] << " " << name[j] << endl;
                flag[i] = 1;
                flag[j] = 1;
            }
        }
    }




}