#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool f(int l, int r, string& s) {
        while(l < r) {
            if (s[l] != s[r]) return false;
            l ++, r --;
        }
        return true;
    }
    void dfs(int u, string& s) {
        if (u == s.length()) {
            ans.push_back(path);
            return;
        }
        for(int i = u; i < s.length(); i ++) {
            if (f(u, i, s)) {
                path.push_back(s.substr(u, i - u + 1));
                dfs(i + 1, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ans;
    }
};