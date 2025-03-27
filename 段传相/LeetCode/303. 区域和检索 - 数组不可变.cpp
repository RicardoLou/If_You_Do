class NumArray {
private:
    vector<int> sums;

public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        this->sums.push_back(0);
        int len = nums.size();
        for (int i = 0; i <len ; i++) {
            sum += nums[i];
            this->sums.push_back(sum);
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */