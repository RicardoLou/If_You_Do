#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    string s, x = "Wo AK le";
    getchar();
    while (n--) {
        getline(cin, s);
        if (s.find("easy") == string::npos && s.find("qiandao") == string::npos) {
            m--;
        }
        if (m < 0) {
            x = s;
            break;
        }
    }
    cout << x;

}