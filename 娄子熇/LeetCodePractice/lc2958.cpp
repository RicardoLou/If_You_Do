#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for(int i = 0, j = 0; i < nums.size(); i ++) {
            cnt[nums[i]] ++;
            while(cnt[nums[i]] > k && j <= i) {
                cnt[nums[j ++]] --;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};