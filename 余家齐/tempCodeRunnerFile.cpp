#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i, j, s = 1,x,z;
    for (i = 3, j = 1; s <= n; i += 2) {
        s += i * 2;
        j++;
    }
    j -= 1;
    z = n - (s - ((i-2) * 2));
    for (i = j, x = 0; i > 0; i--) {
        for (int k = 0; k < x; k++) {
            cout << " ";
        }
        x++;
        for (int k = 1; k <= i * 2 - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    for (i = 2; i <= j; i++) {
        for (int k = 1; k <= j - i; k++) {
            cout << " ";
        }
        for (int k = 1; k <= i * 2 - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << z << endl;
}
