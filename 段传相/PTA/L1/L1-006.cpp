#include<bits/stdc++.h>
using namespace std;

int main() {

    int N, count = 0, tmp = 0, t = 0, sum = 1, max = 0;
    cin >> N;
    int m = sqrt(N);
    //连续因子相乘后还是因子，因此符合题意的因子肯定只在2~sqrt(n)+1之间
    //当我们谈论一个整数 n 的因子时，意思是如果有一个整数 d 能够整除 n 即 n%d=0，
    //那么 d 就是 n 的一个因子。对于任何非质数 n，其因子可以成对出现，比如 d 和 n/d。
    //这里的关键观察是：如果 d 是 n 的一个小于 sqrt(n) 的因子，
    //那么 n/d 必定大于 sqrt(n)，反之亦然。
    //这意味着为了找到 n 的所有因子，
    //我们实际上只需要检查从 2 到 sqrt(n)包括 sqrt(n)之间的数是否能整除 n。
    int yz[m] = {};
    for (int i = 2; i <= m + 1; i++) {
        if (N % i == 0) {
            yz[t++] = i;
        }
    }
    if (t == 0) {
        cout << 1 << endl << N;
    }
    else if (t == 1) {
        cout << 1 << endl << yz[0];
    }
    else {
        for (int i = 0; i < m - 1; i++) {
            sum = yz[i];
            count = 1;
            for (int j = i; j < m - 1; j++) {
                if (yz[j + 1] - yz[j] == 1 && N % (sum * yz[j + 1]) == 0) {
                    sum *= yz[j + 1];
                    count++;
                }
                else {
                    break;
                }
            }
            if (max < count) {
                max = count;
                tmp = i;
            }
        }
        cout << max << endl;
        cout << yz[tmp];
        for (int i = tmp + 1; i < tmp + max; i++) {
            cout << "*" << yz[i];
        }
    }

}