#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_value = -1;
        for(int x : candidates) {
            max_value = max(max_value, x);
        }
        int m = 0;
        while(max_value > 0) {
            max_value >>= 1;
            m ++;
        }
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            int cnt = 0;
            for(int x : candidates) {
                cnt += (x >> i & 1);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};