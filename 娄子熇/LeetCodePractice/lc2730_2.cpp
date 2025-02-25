#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int flag = 0;
        int ans = 1;
        int pre = -1;
        for(int i = 1, j = 0; i < s.length(); i ++) {
            if (s[i] == s[i - 1]) {
                j = pre + 1;
                pre = i - 1;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};