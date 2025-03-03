#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s = 0;
        // 逆向思维
        for(int x : nums) {
            s += x;
        }
        int target = s - x;
        if (target < 0) 
            return -1;
        int ans = -1, n = nums.size();
        int sum = 0;
        for(int i = 0, j = 0; i < n; i ++) {
            sum += nums[i];
            while(sum > target) {
                sum -= nums[j ++];
            }
            if (sum == target) {
                ans = max(ans, i - j + 1);
            }
        }
        return ans < 0 ? -1 : n - ans;
    }
};