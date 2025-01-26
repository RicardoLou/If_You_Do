#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int x : nums) 
            sum += x;
        int ans = 0;
        long long accumulate = 0;
        for(int i = 0; i < nums.size() - 1; i ++) {
            accumulate += nums[i];
            if (2 * accumulate >= sum)
                ans ++;
        }
        return ans;
    }
};