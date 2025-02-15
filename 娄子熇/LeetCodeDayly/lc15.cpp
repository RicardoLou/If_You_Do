#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 2; i ++) {
            int x = nums[i];
            if (i && x == nums[i - 1]) continue; // 重复
            if (x + nums[i + 1] + nums[i + 2] > 0) break;
            if (x + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) continue;
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int s = x + nums[l] + nums[r];
                if (s > 0) {
                    r --;
                } else if (s < 0){ 
                    l ++;
                } else {
                    ans.push_back({x, nums[l], nums[r]});
                    for(++l; l < r && nums[l] == nums[l - 1]; l ++);
                    for(--r; r > l && nums[r] == nums[r + 1]; r --);
                }
            }
        }
        return ans;
    }
};