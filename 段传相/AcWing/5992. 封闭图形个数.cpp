#include<bits/stdc++.h>
using namespace std;

int fb[] = { 1,0,0,0,1,0,1,0,2,1 };
vector<int> v1(2 * (1e5), 0);

bool f(int a, int b) {
    int t = a, al = 0, bl = 0;
    if (t == 0) {
        al += fb[0];
    }
    while (t > 0) {
        al += fb[t % 10];
        t /= 10;
    }
    t = b;
    if (t == 0) {
        bl += fb[0];
    }
    while (t > 0) {
        bl += fb[t % 10];
        t /= 10;
    }
    if (al == bl) {
        return a < b;
    }
    else {
        return al < bl;
    }
    //return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    sort(v1.begin(), v1.begin() + n, f);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << v1[i];
        }
        else {
            cout << ' ' << v1[i];
        }
    }


}