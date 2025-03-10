#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n;
    cin >> n;
    //multiset<int> bh;//有序可重复set
    int bh[100001] = {};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bh[a]++;
    }

    int q = 0, p = 0;
    for (int i = 0; i < 100001; i++) {
        if (bh[i] == 1) {
            q++;
        }
        else if (bh[i] > 2) {
            p += bh[i] - 2;
        }
    }
    if (q > p) {
        cout << p + (q - p) / 2;
    }
    else {
        cout << p;
    }
    return 0;
}