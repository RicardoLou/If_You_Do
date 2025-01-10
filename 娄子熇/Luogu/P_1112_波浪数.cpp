#include<bits/stdc++.h>
using namespace std;

int l, r;
int L, R; // 考虑范围
int k; // 进制

// 判断 l 进制的数是否是波浪数
bool f(int k, int l) {
    int x = k % l;
    k /= l;
    int y = k % l;
    k /= l;
    if (x == y)
        return false;
    while(k) {
        int z = k % l;
        k /= l;
        if (z != x)
            return false;
        if (k) {
            int t = k % l;
            k /= l;
            if (t != y)
                return false;
        }
    }
    return true;
}
// 计算每个数的重数
void layer() {
    for(int i = L; i <= R; i ++) {
        int cnt = 0;
        for(int j = l; j <= r; j ++) {
            if (f(i, j)) {
                cnt ++;
            }
            // 必须要刚刚好
            if (cnt > k)
                break;
        }
        if (cnt == k)
            cout << i << endl;
    }
}
int main() {
    cin >> l >> r >> L >> R >> k;
    layer();
    return 0;
}