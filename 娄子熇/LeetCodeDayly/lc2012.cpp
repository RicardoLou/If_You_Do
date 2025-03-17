#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // 对于每一个值，求前缀最大值和后缀最小值
        vector<int> suf(n);
        // 后缀最小值
        suf[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i --) {
            suf[i] = min(suf[i + 1], nums[i]);
        }
        int pre = nums[0];
        for(int i = 1; i < n - 1; i ++) {
            int x = nums[i];
            if (pre < x && x < suf[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans ++;
            }
            pre = max(pre, nums[i]);
        }
        return ans;
    }
};