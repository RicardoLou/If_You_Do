#include<bits/stdc++.h>
using namespace std;

//¼¦ÍÃÍ¬ÁýÎÊÌâ
int main() {

    int n0, n1, n, num, rsc_min = 100001, flag = 0;
    cin >> n0 >> n1 >> n;
    for (int i = 2; i <= n0; i++) {
        if (n0 % i == 0) {
            for (int j = 2; j <= n1; j++) {
                if (n1 % j == 0) {
                    if (n0 / i + n1 / j == n) {
                        if (abs(i - j) < rsc_min) {
                            rsc_min = abs(i - j);
                            num = i;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (flag) {
        cout << n0 / num << ' ' << n - n0 / num;
    }
    else {
        cout << "No Solution";
    }

}