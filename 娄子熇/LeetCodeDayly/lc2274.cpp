#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        sort(special.begin(), special.end());
        int n = special.size();
        ans = max(special[0] - bottom, top - special[n - 1]);
        for(int i = 0; i < n - 1; i ++) {
            ans = max(ans, special[i + 1] - special[i] - 1);
        }
        return ans;
    }
};