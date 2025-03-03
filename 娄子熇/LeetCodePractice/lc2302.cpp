#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long s = 1;
        long long n = nums.size();
        // 前缀和
        vector<long long> sum(n + 1, 0);
        for(int i = 1; i <= n; i ++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for(int i = 1, j = 1; i <= n; i ++) {
            s = (sum[i] - sum[j - 1]) * (i - j + 1);
            while(s >= k && j <= i) {
                j ++;
                s = (sum[i] - sum[j - 1]) * (i - j + 1);
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};