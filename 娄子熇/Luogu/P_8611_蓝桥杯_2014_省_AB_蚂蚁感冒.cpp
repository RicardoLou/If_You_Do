#include<bits/stdc++.h>
using namespace std;

int a[60];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    // 右侧朝左，左侧朝右
    int l = 0, r = 0;
    int t = abs(a[0]);
    for(int i = 1; i < n; i ++) {
        if (a[i] < 0 && abs(a[i]) > t)
            l ++;
        if (a[i] > 0 && abs(a[i]) < t)
            r ++;      
    }
    // 如果感染者往右走或往左走，并且有一个在右侧或左侧的并且对向
    int ans = 0;
    if (a[0] < 0) {
        if (r == 0) ans = 1;
        else ans = l + r + 1;
    } else {
        if (l == 0) ans = 1;
        else ans = l + r + 1;
    }
    cout << ans << endl;
    return 0;
}