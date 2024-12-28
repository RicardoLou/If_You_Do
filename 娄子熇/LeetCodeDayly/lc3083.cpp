#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        bool vis[26][26];
        for(int i = 0; i < s.length() - 1; i ++) {
            int x = s[i] - 'a';
            int y = s[i + 1] - 'a';
            vis[x][y] = true;
            if (vis[y][x])
                return true;
        }
        return false;
    }
};