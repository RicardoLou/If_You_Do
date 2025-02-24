#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = -1;
        int cnt = 0;
        long long ans = 0;
        for(int x : nums) {
            mx = max(mx, x);
        }
        int i = 0;
        for(int x : nums) {
            if (x == mx) cnt ++;
            while(cnt == k) {
                if (nums[i ++] == mx) cnt --;
            }
            ans += i;
        }
        return ans;
    }
};