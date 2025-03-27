class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> sums;
        sums.push_back(0);
        int len = nums.size(), sum = 0;
        for (int i = 0; i < len; i++) {
            sums.push_back(sums[i] + nums[i]);
        }
        for (int i = 0; i < len; i++) {
            int start = max(0, i - nums[i]);
            sum += sums[i + 1] - sums[start];
        }
        return sum;
    }
};