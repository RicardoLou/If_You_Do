#include<bits/stdc++.h>
using namespace std;

#define int long long

class Solution {
public:
    int minSwaps(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int cnt = 0;
        for(int i = 0; i < s.length(); i ++) {
            if (s[i] == '[' || cnt == 0) cnt ++;
            else {
                cnt --;
            }
        }
        return cnt / 2;
    }
};