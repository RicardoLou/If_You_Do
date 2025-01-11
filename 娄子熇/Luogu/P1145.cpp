#include<bits/stdc++.h>
using namespace std;

int main() {
    int k = 0;
    cin >> k;
    // 一共 k * 2 的人
    bool flag = false;
    int cursor = 0;
    int m = k;
    while(!flag) {
        m ++;
        cursor = 0;
        for(int i = 0; i < k; i ++) {
            cursor = (cursor + m - 1) % (2 * k - i); // 下次要淘汰的人 i 是出去了多少人
            if (cursor < k) 
                // 要淘汰好人了，如果在这之前一直没有找到答案那么说明当前的答案不是正确的，继续往后枚举
                break;
            if (i == k - 1) flag = true; // 坏人都死掉了
        }
    }
    cout << m;
}