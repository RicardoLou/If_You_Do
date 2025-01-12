#include<bits/stdc++.h>
using namespace std;

int main() {

    int a, b, sum = 0, i = 0;
    cin >> a >> b;
    for (; a <= b; a++) {
        i++;
        sum += a;
        cout << setw(5) << a;
        if (i == 5 || a == b) {
            i = 0;
            cout << endl;
        }
    }
    cout << "Sum = " << sum;
}