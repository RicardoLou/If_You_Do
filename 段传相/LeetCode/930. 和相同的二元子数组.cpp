class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int nlen = nums.size(), sum = 0, count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nlen; i++) {
            mp[sum]++;
            sum += nums[i];
            count += mp[sum - goal];//sums[r]-goal=sum[l]
        }
        return count;
    }
};