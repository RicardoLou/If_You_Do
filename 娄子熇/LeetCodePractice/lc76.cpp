#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    bool isCover(int cnts[], int cntt[]) {
        for(int i = 'A'; i <= 'Z'; i ++) {
            if (cnts[i] < cntt[i])
                return false;
        }
        for(int i = 'a'; i <= 'z'; i ++) {
            if (cnts[i] < cntt[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int ansl = -1, ansr = s.length();
        int cnts[130];
        int cntt[130];
        for(char c : t) {
            cntt[c] ++;
        }
        for(int l = 0, r = 0; r < s.length(); r ++) {
            cnts[s[r]] ++;
            while(isCover(cnts, cntt)) {
                // 可以就进去找更小的
                if (r - l < ansr - ansl) {
                    ansr = r;
                    ansl = l;
                }
                cnts[s[l]] --;
                l ++;
            }
        }
        return ansl < 0 ? "" : s.substr(ansl, ansr - ansl + 1);
    }
};