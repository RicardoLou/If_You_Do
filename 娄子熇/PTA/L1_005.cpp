#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<string>> info(1010, vector<string>(2));
    
    for (int i = 0; i < n; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        info[a][0] = s;
        info[a][1] = to_string(b); // 将整数b转换为字符串并赋值
    }

    int m;
    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        cout << info[t][0] << " " << info[t][1] << endl;
    }

    return 0;
}