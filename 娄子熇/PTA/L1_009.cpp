#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
vector<vector<int>> num(N, vector<int>(N));
int GCD(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}
int main() {
    cin >> n;
    string s;
    getline(cin, s);
    int index = 0; 
    for(int i = 0; i < s.length(); i ++) {
        if (s[i] == ' ')
            index ++;
        if (s[i] == '-')
            num[index][2] = 1;
        if (s[i] > '0' && s[i] <= 9) {
            if (i != 0 && s[i - 1] == '/') {
                num[index][1] = s[i] - '0';
            } else{
                num[index][0] = s[i] - '0';
            }
            if (num[index][2] == 1)
                num[index][0] = - num[index][0];
        }
    }
    int gcd = 0;
    // 计算分母的最大公因数
    for(int i = 0; i < index; i ++) {
        gcd = GCD(gcd, num[i][1]);
    }
    for(int i = 0; i < index; i ++) {
        num[i][0] = gcd / num[i][1] * num[i][0];
        num[i][1] = gcd;
    }
    int sonSum = 0;
    for(int i = 0; i < index; i ++) {
        sonSum += num[i][0];
    }
    int t = sonSum / gcd; // 分子凑出来多少整
    cout << t << " ";
    sonSum %= gcd; // 余出来的
    if (sonSum != 0) {
        int divisor = GCD(sonSum, gcd);
        sonSum /= divisor;
        gcd /= divisor;
        cout << sonSum << "/" << gcd;
    }
    return 0;
}