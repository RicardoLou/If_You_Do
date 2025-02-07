#include<bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    int f[1001] = { 0 };
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            f[y]++;
        }
    }

    int max = 0, index = 0;
    for (int i = 0; i < 1001; i++) {
        if (f[i] >= max) {
            max = f[i];
            index = i;
        }
    }
    cout << index << " " << f[index];
}