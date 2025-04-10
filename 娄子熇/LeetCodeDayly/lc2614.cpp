#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
    bool is_prime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return n >= 2; // 1 不是质数
    }

public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int x : {nums[i][i], nums[i][n - 1 - i]}) {
                if (x > ans && is_prime(x)) {
                    ans = x;
                }
            }
        }
        return ans;
    }
};