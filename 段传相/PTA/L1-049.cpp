#include<bits/stdc++.h>
using namespace std;

int main() {

    int N, sum = 0;
    cin >> N;
    int d[N];
    for (int i = 0; i < N; i++) {
        cin >> d[i];
        sum += d[i] = d[i] * 10;
    }

    int zw[sum];
    for (int i = 0; i < sum;) {
        for (int j = 0; j < N; j++) {
            if (d[j] > 0) {
                zw[i] = j + 1;
                d[j]--;
                i++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << '#' << i + 1 << endl;
        int count = 0;
        int pre = 0, x = 2;
        for (int j = 0; j < sum; j++) {
            if (zw[j] == i + 1) {
                if (zw[j] == pre) {
                    cout << j + x++;
                }
                else {
                    cout << j + 1;
                }
                if (count < 9) {
                    cout << ' ';
                }
                if (++count % 10 == 0) {
                    cout << endl;
                    count = 0;
                }
            }
            pre = zw[j];
        }
    }
}