#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int flag = 0;
        int ans = 1;
        // int pre = 0;
        for(int i = 1, j = 0; i < s.length(); i ++) {
            if (s[i] == s[i - 1]) {
                flag ++;
                // pre = i - 1;
            }
            // 两对重复了
            if (flag > 1 && j <= i) {
                j ++;
                while(s[j] != s[j - 1]) {
                    j ++;
                }
                flag = 1;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};