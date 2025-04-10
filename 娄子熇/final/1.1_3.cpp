#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
vector<int> a(N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '<' && a[i] >= 0) {
                cnt++;
                a[i] = -1; // 修改为负数
            }
            if (s[i] == '>' && a[i] <= 0) {
                cnt++;
                a[i] = 1; // 修改为正数
            }
            if (s[i] == 'Z' && 1LL * a[i - 1] * a[i] <= 0) {
                cnt++;
                a[i] = (a[i - 1] > 0 ? 1 : -1); // 修改为与前一个同号
            }
        }
        cout << cnt << endl;
    }
    return 0;
}