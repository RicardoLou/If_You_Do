#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 二分查找函数，返回满足条件的最小右边界
    long long search(int l, int r, const vector<vector<int>>& preCount, const vector<int>& count) {
        int border = l;
        while (l < r) {
            int mid = (l + r) / 2;
            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                // 当前这个字串中的 i（26个字母）出现的次数是否满足要求的字串
                if (preCount[mid][i] - preCount[border - 1][i] < count[i]) {
                    valid = false;
                    break;
                }
            }
            // 进一步缩小边界
            if (valid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    // 主函数：统计有效子串的数量
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        vector<int> count(26, 0);
        
        // 统计 word2 中每个字符的频率
        for (char c : word2) {
            count[c - 'a']++;
        }

        // 构建 preCount 数组
        vector<vector<int>> preCount(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                preCount[i][j] = preCount[i - 1][j];
            }
            preCount[i][word1[i - 1] - 'a']++;
        }

        long long res = 0;
        // 遍历每个起始位置 l，计算符合条件的子串数量
        for (int l = 1; l <= n; ++l) {
            long long r = search(l, n + 1, preCount, count);
            res += n - r + 1;
        }
        return res;
    }
};