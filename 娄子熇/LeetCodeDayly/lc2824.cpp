#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while(l < r) {
            while (l < r && nums[l] + nums[r] >= target) {
                r --;
            }
            while (l < r && nums[l] + nums[r] < target) {
                ans ++;
                r --;
            }
            l ++;
            r = n - 1;
        }
        return ans;
    }
        int countPairs2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while(l < r) {
            if (nums[l] + nums[r] < target) {
                ans += r - l;
                l ++;
            } else {
                r --;
            }
        }
        return ans;
    }
};