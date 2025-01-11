#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 10^5 以内的数，因子个数至多为 128（83160 的因子个数），所以我们可以暴力枚举 n 的因子 k。
    int minAnagramLength(string s) {
        int n = s.length();
        for(int i = 1; i <= n / 2; i ++) {
            // 这一定不会是因子
            if (n % i)
                continue;
            vector<int> cnt1(26, 0);
            // 统计当前这个因子各出现了多少次
            for(int j = 0; j < i; j ++) {
                cnt1[s[j] - 'a'] ++;
            }
            bool flag = true;
            for(int j = i * 2; j <= n; j += i) {
                vector<int> cnt(26, 0);
                for(int k = j - i; k < j; k ++) {
                    cnt[s[k] - 'a'] ++;
                }
                if (cnt != cnt1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return n;
    }
};