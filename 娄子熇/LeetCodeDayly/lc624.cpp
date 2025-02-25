#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mn = 0x3f, mx = -0x3f;
        for(int i = 0; i < arrays.size(); i ++) {
            ans = max(ans, max(mx - arrays[i][0], arrays[i].back() - mn));
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }
        return ans;
    }
};