#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Bx, By;
ll Hx, Hy;
ll dp[30][30], ma[30][30];
int main() {
    cin >> Bx >> By >> Hx >> Hy;
    Bx += 2; By += 2; Hx += 2; Hy += 2;
    dp[2][2] = 1;
    ma[Hx][Hy] = 1;
    ma[Hx - 2][Hy - 1] = 1;
    ma[Hx - 2][Hy + 1] = 1;
    ma[Hx - 1][Hy + 2] = 1;
    ma[Hx + 1][Hy + 2] = 1;
    ma[Hx + 2][Hy + 1] = 1;
    ma[Hx + 2][Hy - 1] = 1;
    ma[Hx + 1][Hy - 2] = 1;
    ma[Hx - 1][Hy - 2] = 1;
    for(int i = 2; i <= Bx; i ++) {
        for(int j = 2; j <= By; j ++) {
            if (i == 2 && j == 2) {
                continue;
            }
            if (ma[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[Bx][By];
    return 0;
}