#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    int getKth(int lo, int hi, int k) {
        vector<vector<int>> res;
        for(int i = lo; i <= hi; i ++) {
            int temp = i;
            int index = 0;
            while(temp != 1) {
                if(temp % 2 == 0) {
                    temp /= 2;
                } else temp = temp * 3 + 1;
                index ++;
            }
            res.push_back({i, index});
        }
        sort(res.begin(), res.end(), cmp);
        return res[k - 1][0];
    }
};