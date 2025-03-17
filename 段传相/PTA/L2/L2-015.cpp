#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    double num[n][k] = {};
    double mx[n] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> num[i][j];
        }
        //cout<<*min_element(&num[i][0],&num[i][0]+k)<<" "<<*max_element(&num[i][0],&num[i][0]+k)<<endl;
        *min_element(&num[i][0], &num[i][0] + k) = 0;
        *max_element(&num[i][0], &num[i][0] + k) = 0;
        for (int j = 0; j < k; j++) {
            mx[i] += num[i][j] * 1.0;
        }
        mx[i] /= k - 2.0;
    }
    sort(mx, mx + n);
    int x = 1;
    while (m--) {
        if (x) {
            printf("%.3f", mx[n - m - 1]);
            x--;
        }
        else {
            printf(" %.3f", mx[n - m - 1]);
        }
    }
}