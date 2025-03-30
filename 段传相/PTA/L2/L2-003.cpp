#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, d;
    cin >> n >> d;
    double jg[n] = {}, zl[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> zl[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> jg[i];
    }

    double avg[n];
    for (int i = 0; i < n; i++) {
        avg[i] = jg[i] / zl[i];
    }

    double max = *max_element(avg, avg + n);
    int index = (max_element(avg, avg + n) - avg);
    double sum = 0;
    while (d) {
        if (d >= zl[index]) {
            d -= zl[index];
            zl[index] = 0;
            sum += jg[index];
            avg[index] = 0;
            max = *max_element(avg, avg + n);
            index = (max_element(avg, avg + n) - avg);
            if (max == 0) {
                break;
            }
        }
        else {
            sum += max * d;
            d = 0;
        }
    }
    printf("%.2f", sum);

}