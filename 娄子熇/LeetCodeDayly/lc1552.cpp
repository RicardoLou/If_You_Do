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
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0;
        int r = (position[position.size() - 1] - position[0]) / (m - 1);
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(position, mid) >= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};