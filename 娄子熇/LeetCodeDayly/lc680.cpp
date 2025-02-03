#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while(l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l ++; r --;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for(int l = 0, r = s.length() - 1; l <= r; l ++, r --) {
            if (s[l] != s[r])
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
        return true;
    }
};