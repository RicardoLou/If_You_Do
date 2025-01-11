#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(int x : nums) {
            if (++cnt[x] > 2)
                return false;
        }
        return true;
    }
};