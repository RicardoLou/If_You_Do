#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int main() {
    int n;
    cin >> n;
    int ans =  0;
    do {
        // 全排列枚举两个断点
        int x = 0;
        for(int i = 0; i < 7; i ++) {
            x = x * 10 + a[i];
            int y = 0;
            for(int j = i + 1; j < 8; j ++) {
                y = y * 10 + a[j];
                int z = 0;
                for(int k = j + 1; k < 9; k ++) {
                    z = z * 10 + a[k];
                }
                if (y % z == 0 && x + y / z == n) {
                    ans ++;
                }
            }
        }
    } while(next_permutation(a, a + 9));
    cout << ans;
    return 0;
}