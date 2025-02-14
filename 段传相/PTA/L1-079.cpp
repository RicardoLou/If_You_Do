#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int a[n];
    for (int& x : a) {
        cin >> x;
    }
    int min = *min_element(a, a + n);
    int max = *max_element(a, a + n);
    int min_c = 0, max_c = 0;
    for (int& x : a) {
        if (x == min) {
            min_c++;
        }
        if (x == max) {
            max_c++;
        }
    }
    cout << min << ' ' << min_c << endl << max << ' ' << max_c;
}