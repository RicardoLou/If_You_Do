#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if (n == 1) {
            return "";
        }
        // 把第一个不等于 a 的字母改成 a
        // 只需找前一半，如果前一半没有不等于 a 的字母，那么后一半肯定也没有
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }
        // 除了回文中心，全是 a
        s.back() = 'b'; // 最后一个字母改成 b
        return s;
    }
};