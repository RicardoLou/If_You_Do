#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;
    stack<int> stk;

    for (int i = 0; i < k; i++) {
        int x = 1;//当前需要的值
        for (int j = 0; j < n; j++) {
            int s;
            cin >> s;
            if (s == x) {
                x++;
                while (!stk.empty() && stk.top() == x) {
                    x++;
                    stk.pop();
                }
            }
            else if (stk.size() < m) {
                stk.push(s);
            }

        }

        cout << (stk.empty() ? "YES" : "NO") << endl;
        while (!stk.empty()) {
            stk.pop();
        }
    }

}