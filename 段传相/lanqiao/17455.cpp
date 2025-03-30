#include <bits/stdc++.h>
using namespace std;

int main() {
    // 请在此处编写代码...
    std::stack<int> a;
    int n, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            a.push(1);
        }
        else if (!a.empty()) {
            a.pop();
        }
        if (a.size() > max) {
            max = a.size();
        }
    }
    cout << max;
    return 0;
}