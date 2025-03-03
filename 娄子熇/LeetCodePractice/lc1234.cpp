#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int balancedString(string s) {
        int ans = s.length();
        int cnt['Z'];
        int m = s.length() / 4;
        for(char c : s) cnt[c] ++;
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) return 0;
        for(int i = 0, j = 0; i < s.length(); i ++) {
            cnt[s[i]] --;
            while(cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                ans = min(ans, i - j + 1);
                ++ cnt[s[j ++]];
            }
        }
        return ans;
    }
};