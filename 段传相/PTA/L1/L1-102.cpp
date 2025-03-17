#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    double jg[n] = {};
    int count[n] = {};
    for (auto& x : jg) {
        cin >> x;
    }

    int a, b;
    double sum = 0;
    while (cin >> a >> b) {
        if (a == 0) {
            break;
        }
        count[a - 1] += b;
        sum += b * jg[a - 1];
    }

    for (int& x : count) {
        cout << x << endl;
    }
    printf("%.2f", sum);

}