class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> aa;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            auto a = find(it + 1, nums.end(), target - *it);
            if (a != nums.end()) {
                // distance返回两个迭代器之间的距离
                aa.push_back(distance(nums.begin(), a));
                aa.push_back(distance(nums.begin(), it));
                break;
            }
        }
        return aa;
    }
};