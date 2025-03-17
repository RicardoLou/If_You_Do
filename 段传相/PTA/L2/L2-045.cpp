#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, count = 0, maxsize = 0;
    cin >> n;
    stack<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (a.empty()) {
            a.push(x);
        }
        else if (x < a.top()) {
            a.push(x);
        }
        else if (b.empty() || x > b.top()) {
            b.push(x);
        }
        else {
            count++;
            if (maxsize<int(a.size())) {
                maxsize = a.size();
            }
            while (!a.empty()) {
                a.pop();
            }
            while (!b.empty() && b.top() > x) {
                a.push(b.top());
                b.pop();
            }
            a.push(x);
        }
    }
    if (maxsize<int(a.size())) {
        maxsize = a.size();
    }
    if (!b.empty()) {
        count++;
    }
    cout << count + 1 << " " << maxsize;

}