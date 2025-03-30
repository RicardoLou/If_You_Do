class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int nextLen = nextCost.size();
        int preLen = previousCost.size();
        vector<long long> nextSums(nextLen * 2 + 1, 0);
        vector<long long> preSums(preLen * 2 + 1, 0);

        for (int i = 0; i < nextLen * 2; i++) {
            nextSums[i + 1] = nextSums[i] + nextCost[i % 26];
            preSums[i + 1] = preSums[i] + previousCost[i % 26];
        }

        long long sum = 0;
        int sLen = s.length();
        for (int i = 0; i < sLen; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            sum += min(nextSums[b < a ? b + 26 : b] - nextSums[a], preSums[(a < b ? a + 26 : a) + 1] - preSums[b + 1]);
        }
        return sum;

    }
};