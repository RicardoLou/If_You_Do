#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check(vector<int>& price, int d) {
        int cnt = 1; // 第一个选择了
        int pre = price[0];
        for(int x : price) {
            if (x >= pre + d) {
                cnt ++;
                pre = x;
            }
        }
        return cnt;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0;
        int r = (price[price.size() - 1] - price[0]) / (k - 1);
        while(l < r) {
            int mid = (r + l + 1) / 2; // 避免死循环
            if (check(price, mid) >= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};