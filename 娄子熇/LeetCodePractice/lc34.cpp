#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty()) return ans;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else l = mid + 1;
        }
        if (nums[l] == target)
            ans[0] = l;
        else return ans;

        r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] > target) {
                r = mid - 1;
            } else l = mid;
        }
        ans[1] = l;
        return ans;
    }
};