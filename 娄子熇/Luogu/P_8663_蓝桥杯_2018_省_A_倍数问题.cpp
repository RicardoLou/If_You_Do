#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxSum = -1;

    // 遍历所有三元组，找最大和
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int c = (2 * k - a[i] - a[j]) % k;
            int sum = a[i] + a[j] + c;
            if (sum % k == 0) {
                maxSum = max(maxSum, sum);
            }
        }
    }

    cout << maxSum << endl;
    return 0;
}