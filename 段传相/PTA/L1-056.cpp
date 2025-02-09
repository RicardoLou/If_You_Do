#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    string names[10001], name;
    int x, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> name >> x;
        sum += x;
        names[x] = name;
    }
    sum = sum / n / 2;
    int a = 0;
    for (int i = 0; i < 10001; i++) {
        if (names[sum - a] != "") {
            cout << sum << ' ' << names[sum - a];
            break;
        }
        else if (names[sum + a] != "") {
            cout << sum << ' ' << names[sum + a];
            break;
        }
        a++;
    }
}