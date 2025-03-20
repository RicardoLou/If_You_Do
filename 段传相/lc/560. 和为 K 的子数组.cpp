class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int nlen = nums.size(), sum = 0, count = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nlen; i++) {
            mp[sum]++;
            sum += nums[i];
            count += mp[sum - k];//sums[r]-k=sum[l]
        }
        return count;
    }
};