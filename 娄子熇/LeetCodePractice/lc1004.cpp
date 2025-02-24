#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int flag = 0;
        int cnt = 0;
        for(int i = 0, j = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) {
                flag ++;
            }
            while(flag > k) {
                if (nums[j] == 0) {
                    flag --;
                }
                j ++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};