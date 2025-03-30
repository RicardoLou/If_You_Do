#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, x, jc = 0, oc = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        x % 2 ? jc++ : oc++;
    }
    cout << jc << ' ' << oc;

}