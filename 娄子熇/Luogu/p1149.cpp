#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
int a[N];
int num[] = {6,2,5,5,4,5,6,3,7,6};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    a[0] = 6;
    for(int i = 1; i <= 2000; i ++) {
        int temp = i;
        while(temp >= 1) {
            a[i] = a[i] + num[temp % 10];
            temp /= 10;
        }
    }
    int ans = 0;
    for(int i = 0; i <= 1000; i ++) {
        for(int j = 0; j <= 1000; j ++) {
            if (a[i] + a[j] + a[i + j] + 4 == n)
                ans ++;
        }
    }
    cout << ans;
    return 0;
}