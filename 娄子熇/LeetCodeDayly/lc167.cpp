#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        for(int i = 0; i < numbers.size(); i ++) {
            int t = numbers[l] + numbers[r];
            if (t > target) {
                r --;
                continue;
            }
            if (t < target) {
                l ++;
                continue;
            }
            if (t == target) {
                return {l + 1, r + 1};
            }
        }
        return {l + 1, r + 1};
    }
};