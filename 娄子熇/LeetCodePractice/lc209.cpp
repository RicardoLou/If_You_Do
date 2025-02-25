#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = nums.size() + 1;
        int s = 0;
        for(int i = 0, j = 0; i < nums.size(); i ++) {
            s += nums[i];
            while(s >= target && j <= i) {
                ans = min(ans, i - j + 1);
                s -= nums[j ++];
            }
        }
        return ans > nums.size() ? 0 : ans;
    }
};