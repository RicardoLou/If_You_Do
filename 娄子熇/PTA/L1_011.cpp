#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int cnt[N];

int main() {
    string s;
    getline(cin, s);  // 读取主串
    string sb;
    getline(cin, sb);        // 读取要过滤的字符集

    // 统计需要过滤的字符
    for (int i = 0; i < sb.length(); i++) {
            cnt[sb[i]]++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (!cnt[s[i]])
            cout << s[i];
    }
    return 0;
}