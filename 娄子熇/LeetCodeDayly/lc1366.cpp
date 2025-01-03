#include<bits/stdc++.h>
using namespace std;

// 排序规则函数
bool cmp(const vector<int>& a, const vector<int>& b) {
    int numTeams = a.size() - 1; // 排名统计数组的最后一位是字母 ASCII 值
    for (int i = 0; i < numTeams; ++i) {
        if (a[i] != b[i]) return a[i] < b[i]; // 按票数升序
    }
    return a[numTeams] < b[numTeams]; // 如果票数相同，按字母升序
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return "";

        int numTeams = votes[0].size();
        vector<vector<int>> rank(26, vector<int>(numTeams + 1, 0));

        // 统计每个字母在每个位置的得票数
        for (const auto& vote : votes) {
            for (int i = 0; i < vote.size(); ++i) {
                char c = vote[i];
                rank[c - 'A'][i]--;                // 使用负数表示更高票数优先
                rank[c - 'A'][numTeams] = c;       // 保存字符的 ASCII 值
            }
        }

        // 使用自定义排序规则
        sort(rank.begin(), rank.end(), cmp);

        string result;
        for (auto r : rank) {
            if (r[numTeams] != 0) result += char(r[numTeams]); // 排除未参与投票的字母
        }
        return result;
    }
};