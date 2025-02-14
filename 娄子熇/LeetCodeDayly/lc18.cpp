#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int a = 0; a < n - 3; a ++) {
            long long x = nums[a];
            if (a && x == nums[a - 1]) continue;
            if (x + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
            if (x + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            for(int b = a + 1; b < n - 2; b ++) {
                long long y = nums[b];
                if (b > a + 1 && y == nums[b - 1]) continue;
                if (x + y + nums[b + 1] + nums[b + 2] > target) break;
                if (x + y + nums[n - 1] + nums[n - 2] < target) continue;
                int l = b + 1, r = n - 1;
                while(l < r) {
                    long long s = x + y + nums[l] + nums[r];
                    if (s > target) {
                        r --;
                    } else if (s < target) {
                        l ++;
                    } else {
                        ans.push_back({(int) x, (int) y, nums[l], nums[r]});
                        for(++ l; l < r && nums[l] == nums[l - 1]; l ++);
                        for(-- r; l < r && nums[r] == nums[r + 1]; r --);
                    }
                }
            }
        }
        return ans;
    }
};