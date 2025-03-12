#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    stack<int> a;
    stack<char> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n - 1; i++) {
        char x;
        cin >> x;
        b.push(x);
    }
    while (!b.empty()) {
        int x = a.top();
        a.pop();
        int y = a.top();
        a.pop();
        char op = b.top();
        b.pop();
        if (op == '+') {
            a.push(y + x);
        }
        else if (op == '-') {
            a.push(y - x);
        }
        else if (op == '*') {
            a.push(y * x);
        }
        else if (op == '/') {
            if (x == 0) {
                cout << "ERROR: " << y << "/0";
                return 0;
            }
            a.push(y / x);
        }
    }
    cout << a.top();
}