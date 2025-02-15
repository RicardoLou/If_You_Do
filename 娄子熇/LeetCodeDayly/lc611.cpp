#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 两边之和大于第三边即可组成三角形

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = n - 1; i > 1; i --) {
            int x = nums[i];
            // 最小的两个都满足，那么从这里到i中每一个都可以
            if (nums[0] + nums[1] > x) {
                ans += (i + 1) * i * (i - 1) / 6;
                break;
            }
            // 最大的两条比当前x还小，后面更不可能大了
            if (nums[i - 1] + nums[i - 2] <= x) {
                continue;
            }
            // 对于每个数进行一次两数之和，两数之和大于这个数即可行
            int l = 0, r = i - 1;
            while(l < r) {
                if (nums[l] + nums[r] <= x) {
                    l ++;
                } else {
                    ans += r - l;
                    r --;
                }
            }
        }
        return ans;
    }
};