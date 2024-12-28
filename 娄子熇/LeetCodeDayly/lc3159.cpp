#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> record;
        for(int i = 0; i < nums.size(); i ++) {
            if (nums[i] == x) {
                record.push_back(i);
            }
        }
        vector<int> ans;
        int cnt = record.size();
        for(int i = 0; i < queries.size(); i ++) {
            if (cnt >= queries[i])
                ans.push_back(record[queries[i] - 1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};