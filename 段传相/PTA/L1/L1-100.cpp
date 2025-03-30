#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, sum = 0;
    cin >> a >> b;
    for (int i = 0; i < b; i++) {
        cin >> c;
        sum += c;
    }
    if (a * (b - 1) < sum) cout << sum - a * (b - 1);
    else cout << 0;

}