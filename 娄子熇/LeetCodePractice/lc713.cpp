#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int ans = 0;
        int n = nums.size();
        long long s = 1;
        for(int i = 0, j = 0; i < n; i ++) {
            s = s * nums[i];
            while(s >= k) {
                s /= nums[j ++];
            }
            ans += i - j + 1; // 子数组可行那么当前这个值也一定行
        }
        return ans;
    }
};