#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        for(int i = 0; i <= s.length() - k; i ++) {
            int sum = stoi(s.substr(i, k));
            if (sum != 0 && num % sum == 0) 
                ans ++;
        }
        return ans;
    }
};