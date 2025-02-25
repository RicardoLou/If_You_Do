#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    string S;
    cin >> S;
    vector<string> ans;
    // 对于每一种组合进行检查是否存在k-1次，并且检查是否可以通过改变一个字符组成这个组合
    for(char c1 = 'a'; c1 <= 'z'; c1 ++) {
        for(char c2 = 'a'; c2 <= 'z'; c2 ++) {
            if (c1 == c2) continue;
            int cnt = 0;
            int flag = 0;
            auto s = S;
            for(int i = 0; i < s.length() - 2; i ++) {
                if (s[i] == c1 and s[i + 1] == c2 and s[i + 2] == c2) {
                    cnt ++;
                    s[i] = s[i + 1] = s[i + 2] = '*'; // 占位符避免出现重复
                }
            }
            for(int i = 0; i < s.length() - 2; i ++) {
                if (s[i] == '*' or s[i + 1] == '*' or s[i + 2] == '*')
                    continue;
                if ((s[i] == c1 and s[i + 1] == c2) or (s[i + 1] == c2 and s[i + 2] == c2) or (s[i] == c1 and s[i + 2] == c2)) {
                    flag = 1;
                }
            }
            if (cnt + flag >= f) {
                string t;
                t += c1;
                t += c2;
                t += c2;
                ans.push_back(t);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) {
        cout << x << endl;
    }
    return 0;
}