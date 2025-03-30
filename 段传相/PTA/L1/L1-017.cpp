#include<bits/stdc++.h>
using namespace std;

int main() {

    string n;
    int count = 0;
    float sum = 1;
    cin >> n;
    if (n[0] == '-') {
        sum *= 1.5;
        n.erase(0, 1);
    }
    float n_len = n.length();
    if ((n[n_len - 1] - '0') % 2 == 0) sum *= 2;
    for (char c : n) {
        if (c == '2') {
            count++;
        }
    }
    cout << fixed << setprecision(2) << count / n_len * sum * 100 << '%';
}