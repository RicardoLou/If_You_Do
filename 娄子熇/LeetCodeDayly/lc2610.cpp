#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int x : nums) {
            cnt[x] ++;
        }
        vector<vector<int>> ans;
        while(!cnt.empty()) {
            vector<int> t;
            for(auto it = cnt.begin(); it != cnt.end();) {
                t.push_back(it -> first); // 数据push进去
                if (--it -> second == 0) {
                    // 次数等于0就没了
                    it = cnt.erase(it);
                } else {
                    it ++;
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};