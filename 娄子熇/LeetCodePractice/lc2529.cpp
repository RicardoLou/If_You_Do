#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        // 找到第一个大于等于0的位置
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < 0) 
                l = mid + 1;
            else r = mid;
        }
        int neg = (nums[l] < 0) ? l + 1 : l;
        l = 0;
        r = n;
        // 找到第一个大于0也就是大于等于1的位置
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < 1) {
                l = mid + 1;
            } else r = mid;
        }
        int pos = l;
        return max(neg, n - pos);
    }
};