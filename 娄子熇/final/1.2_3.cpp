#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
long long a[N][2]; // 用 long long
int n;
long long S;
long long ans = 1e18;

int main() {
    cin >> n >> S;
    int max_c = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
        max_c = max(max_c, (int)a[i][1]); // 这里强转回 int 保证循环正常
    }
    
    for(int i = 0; i <= max_c; i ++) {
        long long cost = i * S; // 集体训练费用
        for(int j = 0; j < n; j ++) {
            if (a[j][1] > i) {
                cost += (a[j][1] - i) * a[j][0]; // 额外个人训练费用
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}