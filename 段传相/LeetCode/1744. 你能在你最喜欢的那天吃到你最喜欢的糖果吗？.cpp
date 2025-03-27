class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int cLen = candiesCount.size(), qLen = queries.size();
        vector<long long> sums(cLen + 1, 0);
        vector<bool> aa(qLen, false);
        for (int i = 0; i < cLen; i++) {
            sums[i + 1] = sums[i] + candiesCount[i];
        }

        for (int i = 0; i < qLen; i++) {
            long long t = 1LL * (queries[i][1] + 1) * queries[i][2];
            if (t > sums[queries[i][0]] && queries[i][1] < sums[queries[i][0] + 1]) {
                aa[i] = true;
            }
        }
        return aa;
    }
};