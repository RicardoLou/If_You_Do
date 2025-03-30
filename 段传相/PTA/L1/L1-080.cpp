#include<bits/stdc++.h>
using namespace std;

int main() {

    int a1, a2, n;
    cin >> a1 >> a2 >> n;

    int arr[n];
    arr[0] = a1;
    arr[1] = a2;
    int a = 0, b = 1, c = 0;

    for (int i = 2; i < n; i++) {
        c = arr[a] * arr[b];
        if (c / 10 == 0) {
            arr[i] = c;

        }
        else {
            arr[i] = c / 10;
            arr[i + 1] = c % 10;
            i++;
        }
        a++;
        b++;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i + 1 < n) {
            cout << ' ';
        }
    }

}