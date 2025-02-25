#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for(int i = 0; n; n >>= 1) {
            ans[i] += n & 1;
            i ^= 1; // 更换奇偶
        }
        return ans;
    }
};  