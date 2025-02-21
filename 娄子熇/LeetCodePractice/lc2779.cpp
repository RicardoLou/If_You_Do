#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, j = 0; i < nums.size(); i ++) {
            // 找交集
            while(nums[j] + k < nums[i] - k and j <= i) {
                j ++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};