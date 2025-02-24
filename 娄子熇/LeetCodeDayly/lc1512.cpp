#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int cnt[110];
        for(int i = 0; i < nums.size(); i ++) {
            ans += cnt[nums[i]] ++;
        }
        return ans;
    }
};