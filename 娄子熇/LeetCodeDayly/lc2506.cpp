#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for(auto& s : words) {
            int mask = 0;
            for(char c : s) {
                // 压缩到一个int里
                mask |= 1 << (c - 'a');
            } 
            ans += cnt[mask] ++;
        }
        return ans;
    }
};