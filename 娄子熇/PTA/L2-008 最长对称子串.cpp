#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(const string& s) {
    int n = s.size();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int center = 0; center < 2 * n - 1; ++center) {
        int left = center / 2;
        int right = left + center % 2;
        // abccba
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            --left;
            ++right;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    getline(cin, s);
    string ans = longestPalindrome(s);
    cout << ans.size() << endl;
    return 0;
}