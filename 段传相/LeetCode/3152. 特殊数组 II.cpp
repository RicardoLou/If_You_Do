class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> aa;

        int nlen = nums.size();
        vector<int> sums(nlen, 1);
        for (int i = 1; i < nlen; i++) {
            if (nums[i] % 2 != nums[i - 1] % 2) {
                sums[i] = sums[i - 1] + 1;
            }
        }
        for (auto x : queries) {
            aa.push_back(sums[x[1]] >= (x[1] - x[0] + 1));
        }
        return aa;
    }
};