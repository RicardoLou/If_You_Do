class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int nlen = nums.size(), qlen = queries.size();
        vector<int> answer(qlen, 0);
        vector<int> sums(nlen + 1, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nlen; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        for (int i = 0; i < qlen; i++) {

            //upper_bound在有序的数组中查找第一个大于n的元素的位置，返回迭代器，内部实现是二分查找
            //lower_bound查找第一个大于等于n的元素位置，其他同上
            answer[i] = upper_bound(sums.begin(), sums.end(), queries[i]) - sums.begin() - 1;

            //暴力循环查找，可以通过全部测试点
            // for(int j=0;j<nlen+1;j++){
            //     if(sums[j]>queries[i]){
            //         answer[i]=j-1;
            //         break;
            //     }else{
            //         answer[i]=j;
            //     }
            // }
        }
        return answer;
    }
};