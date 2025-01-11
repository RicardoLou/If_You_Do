#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAllChartNotNegative(vector<int>& cnt) {
        for(auto x : cnt) {
            if (x < 0)
                return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        vector<int> cnt(26, 0);
        
        // 统计 word2 中每个字符的频率
        for (char c : word2) {
            cnt[c - 'a'] --;
        }

        long long ans = 0;
        int left = 0;
        // 记录子串中的字符出现频率，如果满足word2则可以将窗口向右移动，直到找到可以满足的左边界
        for(char c : word1) {
            cnt[c - 'a'] ++;
            while(isAllChartNotNegative(cnt)) {
                // 左边界移出去
                cnt[word1[left] - 'a'] --;
                left ++;
            }
            ans += left;
        }
        return ans;
    }
};