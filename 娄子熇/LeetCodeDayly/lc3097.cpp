#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i ++) {
            int x = nums[i];
            if (x >= k) {
                return 1;
            }
            for(int j = i - 1; j >= 0 && (nums[j] | x) != nums[j]; j --) {
                nums[j] |= x;
                if (nums[j] >= k) {
                    ans = min(ans, i - j + 1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};