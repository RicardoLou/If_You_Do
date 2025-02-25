#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int, int> cnt;
        int ans = 0;
        for(int i = 0, j = 0; i < n; i ++) {
            cnt[s[i]] ++;
            while(cnt[s[i]] > 1 && j <= i) {
                cnt[s[j]] --;
                j ++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};