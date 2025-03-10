#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    set<string> gzlb;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        gzlb.insert(s);
    }

    int m;
    cin >> m;
    int sum = 0;
    map<string, int> nd;
    for (int i = 0; i < m; i++) {
        string x;
        int a;
        cin >> x >> a;
        sum += a;
        if (gzlb.find(x) == gzlb.end()) {
            nd[x] = a;
        }
    }

    sum /= m;
    int flag = 1;
    for (auto it = nd.begin(); it != nd.end(); it++) {
        if (it->second > sum) {
            flag = 0;
            cout << it->first << endl;
        }
    }
    if (flag) {
        cout << "Bing Mei You";
    }

}