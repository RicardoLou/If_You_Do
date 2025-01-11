#include<bits/stdc++.h>
using namespace std;

int main() {

    string a[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    string b;
    cin >> b;
    int i = 0;
    if (b[0] == '-') {
        cout << "fu ";
        i = 1;
    }
    for (; i < b.length() - 1; i++) {
        cout << a[int(b[i] - '0')] << ' ';
    }
    cout << a[int(b[b.length() - 1] - '0')];
}