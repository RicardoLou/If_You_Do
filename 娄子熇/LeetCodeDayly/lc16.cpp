#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        int minDiff = INT_MAX;
        for(int i = 0; i < n - 2; i ++) {
            int x = nums[i];
            if (i && x == nums[i - 1]) continue; // 相同的数跑过了
            int s = x + nums[i + 1] + nums[i + 2];
            if (s > target) {
                if (s - target < minDiff)
                    ans = s;
                break; // 后面一定无法比当前这个还小，这三个是最小值了
            }
            s = x + nums[n - 1] + nums[n - 2];
            if (s < target) {
                if (target - s < minDiff) {
                    minDiff = target - s;
                    ans = s;
                }
                continue; // 后面基于x的一定无法比当前这个还大，这三个是基于x的最大值了
            }
            
            int l = i + 1, r = n - 1;

            while(l < r) {
                s = x + nums[l] + nums[r];
                if (s == target) 
                    return target;
                if (s > target) {
                    if (s - target < minDiff) {
                        minDiff = s - target;
                        ans = s;
                    }
                    r --;
                } else {
                    if (target - s < minDiff) {
                        minDiff = target - s;
                        ans = s;
                    }
                    l ++;
                }
            }
        }
        return ans;
    }
};