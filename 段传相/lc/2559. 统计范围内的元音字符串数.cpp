class Solution {
public:

    bool isYuanYinStr(string s) {
        return isYuanYin(s[0]) && isYuanYin(s[s.size() - 1]);
    }
    bool isYuanYin(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> sums;
        vector<int> aa;
        sums.push_back(0);
        int wlen = words.size();
        for (int i = 0; i < wlen; i++) {
            sums.push_back(sums[i] + isYuanYinStr(words[i]));
        }
        int qlen = queries.size();
        for (int i = 0; i < qlen; i++) {
            aa.push_back(sums[queries[i][1] + 1] - sums[queries[i][0]]);
        }
        return aa;
    }

};